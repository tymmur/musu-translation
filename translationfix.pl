#!/usr/bin/perl

use strict;
use warnings;


# setup options

my $to_wide_char = 0;
my $to_short_char = 0;

my $allow_new_dialogue = 0;

my $max_lines_in_translation = 1;

# end of setup

# set end of line to always print CLRF
my $CLRF = "\r\n";

if( $^O eq 'MSWin32' )
{
	$CLRF = "\n";
}


# move to the correct working directory
chdir "scripts";


my $empty = sprintf("%c%c", 0x81, 0x40);
my $star_prefix = sprintf("%c%c", 0x81, 0x99);
my $speaker_add = sprintf("%c%c", 0x81, 0x97);


my @japanese;
my $japanese_index;

my $line_count = 0;
my $translated_line_count = 0;
my $byte_count = 0;
my $translated_byte_count = 0;
my $byte_count_block = 0;

my $line_number = 0;


# table for auto translate names
my %name_translation;

foreach (readFile("../names.txt"))
{
	my $japanese = $_;
	my $english = "";
	if (index ($_, " ") != -1)
	{
		$japanese = substr($_, 0, index($_, " "));
		$english  = substr($_,1 + index($_, " "));
	}
	$name_translation{$japanese} = $english;
}

# there are empty names. Force them to be empty with throwing warnings or errors
$name_translation{$empty} = $empty;

sub removeLeadingWhitespace
{
	my ($line) = @_;
	
	while (substr($line, 0, 1) eq " " or substr($line, 0, 1) eq "	" or substr($line, 0, 2) eq $empty)
	{
		if (substr($line, 0, 2) eq $empty)
		{
			$line = substr($line, 2);
		}
		else
		{
			$line = substr($line, 1);
		}
	}
	
	return $line;
}

# setup table to convert to wide characters

my %toWideTable;

for (my $value=0x20; $value < 0x7F; $value++)
{
	my $newvalue = 0;
		
	if ($value >= 0x41 and $value <= 0x5A)
	{
		# uppercase
		$newvalue = 0x8260 + $value - 0x41;
	}
	elsif ($value >= 0x61 and $value <= 0x7A)
	{
		# lowercase
		$newvalue = 0x8281 + $value - 0x61;
	}
	elsif ($value >= 0x30 and $value <= 0x39)
	{
		# numbers
		$newvalue = 0x824F + $value - 0x30;
	}
	
	$toWideTable{ chr($value) } = $newvalue;
}

$toWideTable{ ' ' } = 0x8140;
$toWideTable{ '!' } = 0x8149;
$toWideTable{ '"' } = 0x8167;
$toWideTable{ '#' } = 0x8194;
$toWideTable{ '%' } = 0x8193;
$toWideTable{ '&' } = 0x8195;
$toWideTable{ '\''} = 0x818C;
$toWideTable{ '(' } = 0x8169;
$toWideTable{ ')' } = 0x816A;
$toWideTable{ '*' } = 0x819A;
$toWideTable{ '+' } = 0x817B;
$toWideTable{ ',' } = 0x8143;
$toWideTable{ '-' } = 0x817C;
$toWideTable{ '.' } = 0x8144;
$toWideTable{ '/' } = 0x815E;

# numbers

$toWideTable{ ':' } = 0x8146;
$toWideTable{ ';' } = 0x8147;
$toWideTable{ '<' } = 0x8183;
$toWideTable{ '=' } = 0x8181;
$toWideTable{ '>' } = 0x8184;
$toWideTable{ '?' } = 0x8148;
$toWideTable{ '@' } = 0x8197;

# upper case

$toWideTable{ '[' } = 0x816D;
$toWideTable{ '\''} = 0x814C;
$toWideTable{ ']' } = 0x816E;
$toWideTable{ '^' } = 0x814F;
$toWideTable{ '_' } = 0x8151;
$toWideTable{ '`' } = 0x814D;

# lower case

$toWideTable{ '{' } = 0x816F;
$toWideTable{ '|' } = 0x8162;
$toWideTable{ '}' } = 0x8170;
$toWideTable{ '~' } = 0x8160;

# setup table to convert to regular characters
# this is in reality a reversed hash of %toWideTable

my %toRegularCharacters;

# first fill the hash with wide characters.
# That way we will not run into characters not present in the hash.
for (my $major = 0x81; $major < 0x83; $major++)
{
	for (my $minor = 0x40; $minor <= 0xFF; $minor++)
	{
		my $char = sprintf("%c%c", $major, $minor);
		$toRegularCharacters{ $char } = $char;
	}
}

while (my ($key, $value) = each(%toWideTable))
{
	my $char = sprintf("%c%c", $value >> 8, $value & 0xFF);
	$toRegularCharacters{ $char } = $key;
}

# both start and end " should convert to "
$toRegularCharacters{ sprintf("%c%c", 0x81, 0x68) } = "\"";


sub toWideChar
{
	my ($line) = @_;
	
	my $new = "";
	my $quotation = 0;
	
	while (length($line) > 0)
	{
		my $value = ord(substr($line, 0, 1));
		
		if ($value >= 0x80)
		{
			# already widechar
			$new = $new . substr($line, 0, 2);
			$line = substr($line, 2);
			next;
		}
		
		if (substr($line, 0, 4) eq "<br>")
		{
			# don't convert line breaks to widechar (they will stop working)
			$line = substr($line, 4);
			$new = $new . "<br>";
			next;
		}
		
		my $newvalue = 0;
		
		if ($value >= 0x20 and $value < 0x7F)
		{
			$newvalue = $toWideTable{substr($line, 0, 1)};
			
			if ($value == 0x22)
			{
				if ($quotation == 0)
				{
					$quotation = 1;
				}
				else
				{
					$quotation = 0;
					$newvalue = $newvalue + 1;
				}
			}
			
		}
		
		if ($newvalue == 0)
		{
			print $line . "\n";
			print "Error: don't know how to convert " . $value . "\n";
			exit();
		}
		
		$new = $new . sprintf("%c%c", $newvalue >> 8, $newvalue & 0xFF);
		$line = substr($line, 1);
	}
	return $new;
}

sub toRegularChar
{
	my ($line) = @_;
	
	my $new = "";
	
	while (length($line) > 0)
	{
		my $value = ord(substr($line, 0, 1));
		
		if ($value < 0x80)
		{
			# already regular
			$new = $new . substr($line, 0, 1);
			$line = substr($line, 1);
			next;
		}
			

		my $char = substr($line, 0, 2);
		$line = substr($line, 2);
		
		if ($value == 0x81 or $value == 0x82)
		{
			$char = $toRegularCharacters{$char};
		}
		
		$new = $new . $char;
	}
	return $new;
}

sub convertLine
{
	my ($line) = @_;
	
	if ($to_wide_char == 1)
	{
		return toWideChar($line);
	}
	if ($to_short_char == 1)
	{
		return toRegularChar($line);
	}
	return $line;
}

sub getType
{
	my ($line) = @_;

	if (length $line == 0)
	{
		return "BLANK";
	}
	if (substr($line, 0, 1) eq "#")
	{
		return "COMMENT";
	}
	if (substr($line, 0, 1) eq "@")
	{
		return "COMMAND";
	}
	if (substr($line, 0, 2) eq $speaker_add)
	{
		return "SPEAKER";
	}
	
	my $value = ord(substr($line, 0, 1));
	
	if ($value >= 33 and $value <= 126)
	{
		return "TEXT";
	}
	if ($value >= 0x80)
	{
		return "KANJI";
	}
	
	print "numbers: " . $value . " " . ord(substr($line, 1, 1)) . "\n";
	
	die "can't figure out type for line $line";
}

sub readFile
{
	my ($file) = @_;
	
	open FILE, "<", $file or die $!;
	
	my @array = ();
	

	while (my $line = <FILE>)
	{
		$line =~ s/[\x0D]//g;
		$line =~ s/[\x0A]//g;
		while (substr($line, 0, 1) eq " " or substr($line, 0, 1) eq "	" or substr($line, 0, 2) eq $empty)
		{
			if (substr($line, 0, 2) eq $empty)
			{
				$line = substr($line, 2);
			}
			else
			{
				$line = substr($line, 1);
			}
		}
		
		push(@array, $line);
	}
	
	close FILE;
	
	return @array;
}

sub getJapaneseLines
{
	my($use_extra_dialogue) = @_;

	my $max = scalar @japanese;
	my $i = $japanese_index;
	
	my $type = getType($japanese[$i]);
	
	if ($type eq "SPEAKER")
	{
		$i++;
	}
	
	my @array;
	
	$byte_count_block = 0;
	
	while ($i < $max and getType($japanese[$i]) eq "KANJI")
	{
		my $line = $japanese[$i];
		$byte_count_block += length($line);
		push(@array, $line);
		$i++;
	}
	
	if ($use_extra_dialogue == 1)
	{
		$byte_count_block = 0;
	}
	else
	{
		$byte_count += $byte_count_block;
	}
	
	return @array;
}

# ensure that speaker has the right @
# converts name
# ensures that audio fits the original
# returns the converted line
sub convertSpeakerLine
{
	my($line, $use_extra_dialogue) = @_;
	
	my $japanese_name = substr($japanese[$japanese_index], 2);
	if (index($japanese_name, ",") != -1)
	{
		$japanese_name = substr($japanese_name, 0, index($japanese_name, ","));
	}
	
	my $name = $name_translation{$japanese_name};
	
	
	if (length $name == 0)
	{
		if (substr($line, 0, 1) eq "@")
		{
			$line = $speaker_add . substr($line, 1);
		}
		$name = substr($line, 2);
		
		my $index = index($name, ",");
		if ($index != -1)
		{
			$name = substr($name, 0, $index);
		}
	}
		
	my $audio = "";
	if (index($line, ",") != -1)
	{
		my $index = index($line, ",");
		$audio = substr($line, $index);
	}
	if ($name ne $japanese_name)
	{
		$name = convertLine($name);
	}
	
	my $japanese_audio = $japanese[$japanese_index];
	if ($use_extra_dialogue)
	{
		$japanese_audio = "";
	}
	else
	{
		if (index($japanese_audio, ",") != -1)
		{
			$japanese_audio = substr($japanese_audio, index($japanese_audio, ","));
		}
		else
		{
			$japanese_audio = "";
		}
	}
	
	if ($audio ne $japanese_audio)
	{
		print "audio mismatch\n";
		print "found:    " . $line . "\n";
		print "expected: " . $japanese[$japanese_index] . "\n";
		die;
	}

	return $speaker_add . $name . $audio;
}

sub handleScreenLines
{
	my($use_extra_dialogue, @input) = @_;
	 
	my @jap_lines = getJapaneseLines($use_extra_dialogue);		
	my @lines;
	my @output;
	
	my $first_line = "";
	
	my $has_japanese = 0;
	my $has_translation = 0;
	my $i = 0;
	
	my $translated_lines = 0;
	
	$line_count++;
	
	my $type = getType($input[0]);
	
	if ($type eq "SPEAKER" or $type eq "COMMAND")
	{
		$first_line = convertSpeakerLine($input[0], $use_extra_dialogue);
		push(@lines, $first_line);
		$i = 1;
	}
	
	# put modified lines into @lines
	# ignore unmodified lines
	# store if modified and unmodified lines are found
	while ($i < scalar @input)
	{
		my $newline = $input[$i];
		my $found = 0;
		
		foreach (@jap_lines)
		{
			if ($newline eq $_)
			{
				$found = 1;
				last;
			}
		}
		
		if ($found == 1)
		{
			$has_japanese = 1;
		}
		else
		{
			$has_translation = 1;
		
			$type = getType($newline);
			if ($type eq "SPEAKER" or $type eq "COMMAND")
			{
				@lines = ();
				$newline = convertSpeakerLine($newline, $use_extra_dialogue);
				$has_translation = 0;
			}
			else
			{
				$translated_lines++;
				$newline = convertLine($newline);
			}
			
			push(@lines, $newline);
		}
		$i++;
	}
	
	
	# place Japanese files in comments
	# or print them unmodified if no translation has been found
	if ($has_japanese == 1)
	{
		foreach (@jap_lines)
		{
			if ($has_translation == 1)
			{
				push(@output, "#" . $_);
			}
			else
			{
				push(@lines, $_);
			}
		}
	}
	
	if (scalar @lines > 0 and getType($lines[0]) eq "TEXT")
	{
		# kanji line starting with text
		# inset a kanji whitespace
		$lines[0] = $empty . $lines[0];
	}
	
	if ($has_translation == 1)
	{
		if ($max_lines_in_translation < $translated_lines)
		{
			print "Too many lines at " . $line_number . " (estimated)\n";
			foreach (@lines)
			{
				print $_ . $CLRF;
			}
			die;
		}
	
		$translated_line_count++;
		$translated_byte_count += $byte_count_block;
	}
	
	foreach (@lines)
	{
		push(@output, $_);
	}
	
	# always end with a blank line
	push(@output, "");
	
	return @output;
}

sub getNextJapType
{
	my $max = scalar @japanese;
	
	if ($max <= $japanese_index)
	{
		return "MAX";
	}

	if ($japanese_index == -1)
	{
		$japanese_index = 0;
	}
	else
	{
		my $type = getType($japanese[$japanese_index]);
		
		$japanese_index = $japanese_index + 1;
		
		if ($max > $japanese_index and ($type eq "SPEAKER" or $type eq "KANJI"))
		{
			while ($max > $japanese_index and getType($japanese[$japanese_index]) eq "KANJI")
			{
				$japanese_index = $japanese_index + 1;
			}
		}
	}
	
	my $type;
	
	while ($max > $japanese_index and (($type = getType($japanese[$japanese_index])) eq "BLANK" or $type eq "COMMENT"))
	{
		$japanese_index = $japanese_index + 1;
	}
	
	if ($max <= $japanese_index)
	{
		return "MAX";
	}
	
	my $new = $japanese_index + 1;
	
	return $type;
}


sub handleFile
{
	my ($file) = @_;
	
	print $file . "\n";
	
	$japanese_index = -1;
	
	@japanese = readFile("../original/" . $file);
	my @translated = readFile($file);
	
	my @output;
	
	my $last_was_blank = 0;
	my $dialogue_added = 0;
	
	for ($line_number =0; $line_number < scalar @translated; $line_number++)
	{
		my $line = $translated[$line_number];
		my $type = getType($line);
		my $add_kanji_to_text = 0;
		
		if ($type eq "BLANK")
		{
			if ($last_was_blank == 0)
			{
				push(@output, $line);
			}
			$last_was_blank = 1;
			next;
		}
		
		$last_was_blank = 0;
		
		if ($type eq "COMMENT")
		{
			push(@output, $line);
			
			if ($line eq "#SCRIPT ADD DIALOGUE")
			{
				$dialogue_added = $allow_new_dialogue;
			}
			next;
		}
		
		if ($dialogue_added == 1)
		{
			if (getType($japanese[$japanese_index]) eq "KANJI" and $type eq "TEXT")
			{
				# new dialogue needs to start with a kanji
				$add_kanji_to_text = 1;
			}
		}
		else
		{
			my $jap_type = getNextJapType();
			
			if ($jap_type ne $type)
			{
				if ($jap_type eq "SPEAKER" and $type eq "COMMAND")
				{
					# wrong type of @
					$type = "KANJI";
				}
				elsif ($jap_type eq "KANJI" and $type eq "TEXT")
				{
					$add_kanji_to_text = 1;
				}
				else
				{
					print "mismatched lines in " . $file . "\n";
					print "jap " .$jap_type . "	" . "	" . ($japanese_index + 1) . "	" . $japanese[$japanese_index] . "\n";
					print "eng " .$type . "	" . "	" . ($line_number + 1) . "	" . $line . "\n";
			
					exit();
				}
			}
		}
		
		
		if ($type eq "SPEAKER" or $type eq "KANJI" or ($type eq "TEXT" and $add_kanji_to_text == 1))
		{
			my @lines;
			
			if ($type eq "SPEAKER")
			{
				push(@lines, $line);
				$line_number++;
			}
			
			while (getType($translated[$line_number]) ne "BLANK" and getType($translated[$line_number]) ne "COMMENT")
			{
				push(@lines, $translated[$line_number]);
				$line_number++;
			}
			
			foreach((handleScreenLines($dialogue_added, @lines)))
			{
				push(@output, $_);
			}

			$last_was_blank = 1;
			$dialogue_added = 0;
			next;
		}
		
		
		$dialogue_added = 0;
		
		if ($type eq "TEXT" and index($line, "select") != -1)
		{
			my $temp_line = substr($line, index($line, "select") + 6);
			$temp_line = removeLeadingWhitespace($temp_line);
			if (substr($temp_line, 0, 3) eq "sel")
			{
				$line_count++;
				if ($line ne $japanese[$japanese_index])
				{
					$translated_line_count++;
				}
				push(@output, $line);
				next;
			}
		}
		
		if ($line ne $japanese[$japanese_index])
		{
			print "mismatched lines in " . $file . "\n";
			print "expected " . "	" . ($japanese_index + 1) . "	" .  $japanese[$japanese_index] . "\n";
			print "found    " . "	" . ($line_number + 1) . "	" .  $line . "\n";
			
			exit();
		}
		
		push(@output, $line);
	}
	
	if (1)
	{
		open FILE, ">", $file or die $!;
	
		foreach (@output)
		{
			print FILE $_ . $CLRF;
		}
		close FILE;
	}
}

sub makeStatusLine
{
	my ($file, $translated, $total, $byte_translated, $byte_total) = @_;
	
	my $percentage = 10000;
	
	if ($total > 0)
	{
		use integer;
		$percentage = (10000 * $translated) / $total;
	}
	
	$file = $file . "\t\t" . $percentage . "\t" . $translated . "\t" . $total . "\t\t";
	
	$percentage = 10000;
	if ($byte_total > 0)
	{
		use integer;
		$percentage = (10000 * $byte_translated) / $byte_total;
	}
	
	$file = $file . $percentage . "\t" . $byte_translated . "\t" . $byte_total;
	
	return $file . $CLRF;
}



sub loadFromScriptsInc
{
	my $status_file = "../translation_status.txt";
	
	my @file_status;
	my @group_status;
	
	my $group = "main";
	my $group_lines = 0;
	my $group_translated_lines = 0;
	my $group_byte_count = 0;
	my $group_translated_byte_count = 0;
	
	my $total_lines = 0;
	my $total_translated_lines = 0;
	my $total_byte_count = 0;
	my $total_translated_byte_count = 0;
	
	if (-e $status_file)
	{
		unlink($status_file);
	}

	foreach (readFile("scripts.ini"))
	{
		if (substr($_, 0, 7) eq "scripts")
		{
			my $file = substr($_, 8);
			$file =~ s/\\/\//g;
			handleFile $file;
			
			push(@file_status, makeStatusLine("$file", $translated_line_count, $line_count, $translated_byte_count, $byte_count));
				
			$group_lines                 += $line_count;
			$group_translated_lines      += $translated_line_count;
			$group_byte_count            += $byte_count;
			$group_translated_byte_count += $translated_byte_count;
				
			$line_count = 0;
			$translated_line_count = 0;
			$byte_count = 0;
			$translated_byte_count = 0;
		}
		elsif (substr($_, 0, 13) eq "#SCRIPT GROUP")
		{
			push(@group_status, makeStatusLine($group, $group_translated_lines, $group_lines, $group_translated_byte_count, $group_byte_count));
			
			$total_lines                 += $group_lines;
			$total_translated_lines      += $group_translated_lines;
			$total_byte_count            += $group_byte_count;
			$total_translated_byte_count += $group_translated_byte_count;
			
			$group_lines = 0;
			$group_translated_lines = 0;
			$group_byte_count = 0;
			$group_translated_byte_count = 0;
			
			$group = substr($_, 14);
		}
	}
	
	open FILE, ">", $status_file or die $!;
	
	print FILE "\t\t\tLINES\t\t\t\tBYTES" . $CLRF;
	print FILE "File\t\tpercentage\ttranslated\ttotal\t\tpercentage\ttranslated\ttotal" . $CLRF;
	
	print FILE makeStatusLine("TOTAL", $total_translated_lines, $total_lines, $total_translated_byte_count, $total_byte_count);
	
	foreach (@group_status)
	{
		print FILE $_;
	}
	
	foreach (@file_status)
	{
		print FILE $_;
	}
	close FILE;
}

if ($#ARGV >= 0)
{
	handleFile $ARGV[0];
}
else
{
	loadFromScriptsInc;
}