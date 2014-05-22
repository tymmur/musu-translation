#!/usr/bin/perl

use strict;
use warnings;


my $to_wide_char = 0;
my $to_short_char = 0;


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
	
	if (substr($line, 0, 1) eq "@")
	{
		$line = $speaker_add . substr($line, 1);
	}
	
	my $name = substr($line, 2);
		
	my $audio = "";
	if (index($name, ",") != -1)
	{
		my $index = index($name, ",");
		$audio = substr($name, $index);
		$name = substr($name, 0, $index);
	}
	
	$name = convertLine($name);
	
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
	
	for (my $i=0; $i < scalar @translated; $i++)
	{
		my $line = $translated[$i];
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
				$dialogue_added = 1;
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
					print "eng " .$type . "	" . "	" . ($i + 1) . "	" . $line . "\n";
			
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
				$i++;
			}
			
			while (getType($translated[$i]) ne "BLANK")
			{
				push(@lines, $translated[$i]);
				$i++;
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
		
		if ($type eq "TEXT" and index($line, "select") != -1 and index($line, "sel") != -1)
		{
			$line_count++;
			if ($line ne $japanese[$japanese_index])
			{
				$translated_line_count++;
			}
			push(@output, $line);
			next;
		}
		
		if ($line ne $japanese[$japanese_index])
		{
			print "mismatched lines in " . $file . "\n";
			print "expected " . "	" . ($japanese_index + 1) . "	" .  $japanese[$japanese_index] . "\n";
			print "found    " . "	" . ($i + 1) . "	" .  $line . "\n";
			
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
	
	my $percentage = 1;
	
	if ($total > 0)
	{
		$percentage = $translated / $total;
	}
	
	$file = $file . "\t\t" . $percentage . "\t" . $translated . "\t" . $total . "\t\t";
	
	$percentage = 1;
	if ($byte_total > 0)
	{
		$percentage = $byte_translated / $byte_total;
	}
	$file = $file . $percentage . "\t" . $byte_translated . "\t" . $byte_total;
	
	return $file . $CLRF;
}

my $total_lines = 0;
my $total_translated_lines = 0;
my $total_byte_count = 0;
my $total_translated_byte_count = 0;
my @file_status;

sub handleDir
{
	my ($dirname, $level) = @_;
	opendir my($dh), $dirname or die "Couldn't open dir '$dirname': $!";
	my @files = grep { !/^\.\.?$/ } readdir $dh;
	closedir $dh;
	
	my $status_file = "../translation_status.txt";
	
	if (-e $status_file)
	{
		unlink($status_file);
	}

	
	foreach (@files)
	{
		next if (substr ($_, 0, 1) eq ".");
	
		my $filename = $dirname . "/" . $_;
		
		if ($dirname eq ".")
		{
			$filename = $_;
		}
		
		if (-d $filename)
		{
			handleDir($filename, ($level + 1));
		}
		else
		{
			if (substr($filename, -4) eq ".txt")
			{
				handleFile $filename;
				
				push(@file_status, makeStatusLine("$filename", $translated_line_count, $line_count, $translated_byte_count, $byte_count));
				
				$total_lines                 += $line_count;
				$total_translated_lines      += $translated_line_count;
				$total_byte_count            += $byte_count;
				$total_translated_byte_count += $translated_byte_count;
				
				$line_count = 0;
				$translated_line_count = 0;
				$byte_count = 0;
				$translated_byte_count = 0;
			}
		}
	}
	
	return if $level > 0;
	
	open FILE, ">", $status_file or die $!;
	
	print FILE "\t\t\tLINES\t\t\t\tBYTES" . $CLRF;
	print FILE "File\t\tpercentage\ttranslated\ttotal\t\tpercentage\ttranslated\ttotal" . $CLRF;
	
	print FILE makeStatusLine("TOTAL", $total_translated_lines, $total_lines, $total_translated_byte_count, $total_byte_count);
	
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
	handleDir(".", 0);
}