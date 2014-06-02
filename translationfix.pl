#!/usr/bin/perl

use strict;
use warnings;


# setup options

my $to_wide_char = 0;
my $to_short_char = 0;

my $allow_new_dialogue = 0;

my $count_kana_lines = 0;

my $max_lines_in_translation = 1;

# WARNING: this action can't be reverted
# do NOT commit the output to git
# the output will not be accepted again by the script!
my $split_lines = 0;

# auto newline setup
my $NUM_LINES = 4;
my $NUM_CHARS = 37;

# debug options
# make the game print whenever it passes a new label

my $add_label_text = 0;

# end of setup

my @common_route_files;

push(@common_route_files, "prologue/youzyo.txt");
push(@common_route_files, "prologue/youzyo2.txt");
push(@common_route_files, "prologue/youzyo3.txt");
push(@common_route_files, "prologue/youzyoG.txt");
push(@common_route_files, "schedule/setsumei.txt");
push(@common_route_files, "day/suika1.txt");
push(@common_route_files, "training/training_in.txt");
push(@common_route_files, "training/training_mikan_01.txt");
push(@common_route_files, "day/0121_mikan_virginity_lose_day_after.txt");
push(@common_route_files, "day/miu1.txt");
push(@common_route_files, "day/seiji1.txt");
push(@common_route_files, "day/zakuro1.txt");
push(@common_route_files, "day/seiji2.txt");
push(@common_route_files, "day/suika2.txt");
push(@common_route_files, "day/seiji3.txt");
push(@common_route_files, "day/erocute.txt");
push(@common_route_files, "day/0302_shizuku_kidnap.txt");
push(@common_route_files, "day/0303_shizuku_kidnap_day_after.txt");
push(@common_route_files, "day/suika3.txt");
push(@common_route_files, "day/seiji4.txt");
push(@common_route_files, "day/zakuro2.txt");
push(@common_route_files, "day/0325_shizuku_return.txt");
push(@common_route_files, "day/closing_ceremony1.txt");
push(@common_route_files, "day/new_school_term1.txt");
push(@common_route_files, "day/yuzu1.txt");
push(@common_route_files, "day/yuzu2.txt");
push(@common_route_files, "day/zakuro3.txt");
push(@common_route_files, "day/seiji5.txt");
push(@common_route_files, "day/miu2.txt");
push(@common_route_files, "day/golden_week1.txt");
push(@common_route_files, "day/golden_week2.txt");
push(@common_route_files, "day/yuzu3.txt");
push(@common_route_files, "day/mothers_day.txt");
push(@common_route_files, "day/suika4.txt");
push(@common_route_files, "day/miu3.txt");
push(@common_route_files, "day/zakuro4.txt");
push(@common_route_files, "day/seiji6.txt");
push(@common_route_files, "day/yuzu4.txt");
push(@common_route_files, "day/zakuro5.txt");
push(@common_route_files, "day/tanabata.txt");
push(@common_route_files, "day/yuzu5.txt");
push(@common_route_files, "day/zakuro6.txt");
push(@common_route_files, "day/zakuro7.txt");
push(@common_route_files, "day/closing_ceremony2.txt");
push(@common_route_files, "day/radio_exercise.txt");
push(@common_route_files, "day/school_day1.txt");
push(@common_route_files, "day/yuzu6.txt");
push(@common_route_files, "day/zakuro8.txt");
push(@common_route_files, "day/school_day2.txt");
push(@common_route_files, "day/pool_everyone.txt");
push(@common_route_files, "day/game_seal_(suika).txt");
push(@common_route_files, "day/summer_festival.txt");
push(@common_route_files, "day/school_day3.txt");
push(@common_route_files, "day/yuzu7.txt");

my $count_this_line = $count_kana_lines;

# set end of line to always print CLRF
my $CLRF = "\r\n";

if( $^O eq 'MSWin32' )
{
	$CLRF = "\n";
}

if ($split_lines == 1)
{
	# split lines only works on wide chars
	$to_wide_char = 1
}

# move to the correct working directory
chdir "scripts";

my $last_file_file = "../last_file.txt";
my $active_file = "main.txt";

my $empty = sprintf("%c%c", 0x81, 0x40);
my $star_prefix = sprintf("%c%c", 0x81, 0x99);
my $speaker_add = sprintf("%c%c", 0x81, 0x97);
my $period = sprintf("%c%c", 0x81, 0x44);
my $question_mark = sprintf("%c%c", 0x81, 0x48);
my $explanation_mark = sprintf("%c%c", 0x81, 0x49);


my @japanese;
my $japanese_index;

my $line_count = 0;
my $translated_line_count = 0;
my $byte_count = 0;
my $translated_byte_count = 0;
my $byte_count_block = 0;

my $line_number = 0;


sub die_local
{
	open FILE, ">", $last_file_file or die $!;
	print FILE $active_file . $CLRF;
	close FILE;
	
	die @_;
}


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

sub removeTrailingWhitespace
{
	my ($line) = @_;
	
	$line = removeLeadingWhitespace($line);
	
	if (index ($line, " ") != -1)
	{
		$line = substr($line, 0, index($line, " "));
	}
	if (index ($line, "	") != -1)
	{
		$line = substr($line, 0, index($line, "	"));
	}
	if (index ($line, $empty) != -1)
	{
		$line = substr($line, 0, index($line, $empty));
	}
	if (index ($line, ";") != -1)
	{
		$line = substr($line, 0, index($line, ";"));
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

# list of "words", which should not be converted to widechar

my @control_words;

push(@control_words, "<br>");
push(@control_words, "[_PRICE]");
push(@control_words, "[ADD_KENKOU]");
push(@control_words, "[ADD_KIRYOKU]");
push(@control_words, "[ADD_ATAMA]");
push(@control_words, "[ADD_KARADA]");
push(@control_words, "[ADD_KOKORO]");

sub getControlLength
{
	my ($line) = @_;
	
	foreach (@control_words)
	{
		my $length = length($_);
		if (substr($line, 0, $length) eq $_)
		{
			return $length;
		}
	}
	return 0;
}


my @last_read_file;


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
		
		my $length = getControlLength($line);
		if ($length > 0)
		{
			$new = $new . substr($line, 0, $length);
			$line = substr($line, $length);
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
	
	die_local "can't figure out type for line $line";
}

sub readFile
{
	my ($file) = @_;
	
	open FILE, "<", $file or die_local $!;
	
	my @array = ();
	@last_read_file = ();
	

	while (my $line = <FILE>)
	{
		$line =~ s/[\x0D]//g;
		$line =~ s/[\x0A]//g;
		
		push(@last_read_file, $line);
		
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

sub isFileModified
{
	my(@new_lines) = @_;
	
	if (scalar @new_lines != scalar @last_read_file)
	{
		return 1;
	}
	
	for (my $line_number =0; $line_number < scalar @last_read_file; $line_number++)
	{
		if ($new_lines[$line_number] ne $last_read_file[$line_number])
		{
			return 1;
		}
	}
	return 0;
}

sub checkLineForKanji
{
	my ($line) = @_;
	return if $count_this_line == 1;
	
	while (length $line > 0)
	{
		my $value = ord(substr($line, 0, 1));
		if ($value > 0x84)
		{
			$count_this_line = 1;
			return;
		}
		my $length = 1;
		$length = 2 if $value >= 0x80;
		$line = substr($line, $length);
	}
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
	
	$count_this_line = $count_kana_lines;
	
	while ($i < $max and getType($japanese[$i]) eq "KANJI")
	{
		my $line = $japanese[$i];
		$byte_count_block += length($line);
		push(@array, $line);
		$i++;
		checkLineForKanji($line);
	}
	
	if ($use_extra_dialogue == 1)
	{
		$byte_count_block = 0;
	}
	elsif ($count_this_line == 1)
	{
		$byte_count += $byte_count_block;
	}
	
	return @array;
}

sub splitSentence
{
	my ($line) = @_;
	
	my @output;
	
	my $buffer;
	
	while (length $line > ($NUM_CHARS * 2))
	{
		my $buffer = substr($line, 0, ($NUM_CHARS * 2));
		
		my $index = rindex($buffer, $empty);
		
		my $offset = 2;
		
		if ($index == -1)
		{
			$index = ($NUM_CHARS * 2);
			$offset = 0;
		}
		
		push (@output, substr($line, 0, $index));
		$line = substr($line, $index + $offset);
	}
	
	if (length $line > 0)
	{
		push (@output, $line);
	}
	
	return @output;
}

sub splitLine
{
	my ($speaker, $text) = @_;

	my @lines;
	
	my $string = "";
	my $last_char = "";
	
	
	if (index($speaker, ",") != -1)
	{
		$speaker = substr($speaker, 0, index($speaker, ","));
	}
	
	while (length $text > 0)
	{
		my $length = getControlLength($text);
		if ($length > 0)
		{
			$string = $string . substr($text, 0, $length);
			$text = substr($text, $length);
			next;
		}
	
		my $char = substr($text, 0, 2);
		$text = substr($text, 2);
		
		
		if ($char eq $empty)
		{
			if ($last_char eq $period or $last_char eq $question_mark or $last_char eq $explanation_mark)
			{
				push(@lines, $string);
				$string = "";
				$last_char = $empty;
				next;
			}
		}
		
		if (length($string) > 0 or $char ne $empty)
		{
			$string .= $char;
			
		}
		$last_char = $char;
	}
	
	if (length($string) > 0)
	{
		push(@lines, $string);
	}
	
	my $line = "";
		
	my @buffer;
	
	foreach my $input (@lines)
	{
		if (length $line > 0 and length $line < ($NUM_CHARS * 2))
		{
			$line .= $empty;
		}
		
		if (length($input) + length($line) <= ($NUM_CHARS * 2))
		{
			$line .= $input;
			next;
		}
		
		if (length $line > 0)
		{
			push(@buffer, $line);
			$line = "";
		}
		
		my $num_lines = scalar @buffer;
		
		foreach (splitSentence($input))
		{
			push(@buffer, $_);
		}
		
		$line = pop(@buffer);
	}
	
	if (length ($line) > 0)
	{
		push(@buffer, $line);
	}
	
	
	if (scalar @buffer > $NUM_LINES)
	{
		# failed to fit text
		# try again while not caring about splitting sentences, just words
		
		@buffer = ();
		$line = "";
		
		foreach my $input (@lines)
		{
			my $line_at_start = $line;
			
			if (length $line > 0)
			{
				$line .= $empty;
			}
			
			$line .= $input;
			
			my @previous_buffer = (@buffer);
			
			foreach (splitSentence($line))
			{
				push(@buffer, $_);
			}
			
			if (scalar @buffer > $NUM_LINES and scalar @previous_buffer < $NUM_LINES)
			{
				if (@previous_buffer > ($NUM_LINES - 2))
				{
					@buffer = (@previous_buffer);
					push(@buffer, $line_at_start);
					push(@buffer, "");
					push(@buffer, $speaker);
					foreach (splitSentence($input))
					{
						push(@buffer, $_);
					}
				}
				else
				{
					# sentence is too long and is has to be split
					splice @buffer, $NUM_LINES, 0, "", $speaker;
				}
			}
			$line = pop(@buffer);
		}
		
		if (length ($line) > 0)
		{
			push(@buffer, $line);
		}
	}
	
	
	my @output;
	
	my $prev_line = "temp";
	
	foreach (@buffer)
	{
		if (length($_) > 0 and substr($_, 0, 2) ne $speaker_add)
		{
			if (length($prev_line) > 0 and substr($prev_line, 0, 2) ne $speaker_add)
			{
				$prev_line .= "<br>";
			}
		}
		push(@output, $prev_line);
		$prev_line = $_;
	}
	
	push(@output, $prev_line);
	
	shift @output;
	
	return @output;
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
		die_local;
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
	
	my $speaker = "";
	
	my $type = getType($input[0]);
	
	if ($type eq "SPEAKER" or $type eq "COMMAND")
	{
		$first_line = convertSpeakerLine($input[0], $use_extra_dialogue);
		push(@lines, $first_line);
		$i = 1;
		$speaker = $first_line;
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
				$speaker = $newline;
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
	
	$line_count++ if ($count_this_line == 1);
	
	if ($has_translation == 1)
	{
		if ($max_lines_in_translation < $translated_lines)
		{
			print "Too many lines at " . $line_number . " (estimated)\n";
			foreach (@lines)
			{
				print $_ . $CLRF;
			}
			die_local;
		}
	
		if ($count_this_line == 1)
		{
			$translated_line_count++;
			$translated_byte_count += $byte_count_block;
		}
		
		if ($split_lines)
		{
			my $text = pop(@lines);
			foreach (splitLine($speaker, $text))
			{
				push(@lines, $_);
			}
		}
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

sub makeUnnamedShop
{
	my ($file) = @_;
	
	return if ($file ne "item/shop_buy.txt" and $file ne "item/shop_sel.txt");
	
	# use byte values for Subuta-san's names as that will keep the script working in the ASCII area and avoid charset issues.
	my $to_name   = $speaker_add . $name_translation{sprintf( "%c%c%c%c%c%c%c%c", 147, 88,  136, 245, 130, 179, 130, 241)};
	my $from_name = $speaker_add . $name_translation{sprintf( "%c%c%c%c%c%c%c%c", 145, 131, 138, 87,  130, 179, 130, 241)};
	
	if ($to_wide_char == 1)
	{
		$from_name = toWideChar($from_name);
		$to_name = toWideChar($to_name);
	}

	my $name_length = length $from_name;
	
	my $out_file = substr($file, 0, 13) . "_unnamed.txt";
	
	my @output = ();
	push(@output, "###");
	push(@output, "### AUTOGENERATED FILE");
	push(@output, "###  DO NOT EDIT");
	push(@output, "###");
	
	my $script_ignore = 0;
	
	foreach my $line (readFile($file))
	{
		if ($script_ignore)
		{
			$script_ignore = 0 if ($line eq "#SCRIPT IGNORE END");
			next;
		}
		
		if ($line eq "#SCRIPT IGNORE")
		{
			$script_ignore = 1;
			next;
		}
		
		next if substr($line, 0, 1) eq "#";
		
		if (substr($line, 0, 4) eq "goto" or substr($line, 0, 5) eq "label")
		{
			$line .= "_unnamed";
		}
		elsif (substr($line, 0, 8) eq "if _ITEM")
		{
			if (index($line, "goto") != -1)
			{
				$line .= "_unnamed";
			}
		}
		elsif (substr($line, 0, $name_length) eq $from_name)
		{
			$line = $to_name . substr($line, $name_length);
		}
		
		push(@output, $line);
	}
	
	my $write_file = 1;
	
	if (-e $out_file)
	{
		readFile($out_file);
		$write_file = isFileModified(@output);
	}
	
	if ($write_file == 1)
	{
		open FILE, ">", $out_file or die_local $!;
	
		foreach (@output)
		{
			print FILE $_ . $CLRF;
		}
		close FILE;
	}
}

sub handleFile
{
	my ($file) = @_;
	
	$active_file = $file;
	
	print $file . "\n";
	
	$japanese_index = -1;
	
	@japanese = readFile("../original/" . $file);
	my @translated = readFile($file);
	
	my @output;
	
	my $last_was_blank = 0;
	my $dialogue_added = 0;
	my $script_ignore = 0;
	
	for ($line_number =0; $line_number < scalar @translated; $line_number++)
	{
		my $line = $translated[$line_number];
		my $type = getType($line);
		my $add_kanji_to_text = 0;
		
		if ($script_ignore)
		{
			push(@output, $line);
			$script_ignore = 0 if ($line eq "#SCRIPT IGNORE END");
			next;
		}
		
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
			elsif ($line eq "#SCRIPT IGNORE")
			{
				$script_ignore = 1;
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
			
			while (getType($translated[$line_number]) ne "BLANK")
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
		
		if (substr($japanese[$japanese_index], 0, 12) eq "screen_flash" and index($line, "screen_flash") != -1)
		{
			push(@output, "if disable_screen_flash=0 then " . $japanese[$japanese_index]);
			next;
		}
		
		if ($line ne $japanese[$japanese_index])
		{
			print "mismatched lines in " . $file . "\n";
			print "expected " . "	" . ($japanese_index + 1) . "	" .  $japanese[$japanese_index] . "\n";
			print "found    " . "	" . ($line_number + 1) . "	" .  $line . "\n";
			
			exit();
		}
		
		push(@output, $line);
		
		if ($add_label_text == 1 and substr($line, 0, 5) eq "label")
		{
			my $label_string = "label " . removeTrailingWhitespace(substr($line, 5));
			$label_string = toWideChar($label_string);
			push(@output, "");
			push(@output, $label_string);
			push(@output, "");
		}
	}
	
	if (isFileModified(@output) == 1)
	{
		open FILE, ">", $file or die_local $!;
	
		foreach (@output)
		{
			print FILE $_ . $CLRF;
		}
		close FILE;
	}
	
	makeUnnamedShop($file);
	
	if (-e $last_file_file)
	{
		unlink($last_file_file);
	}
}

my %file_status_hash;

sub makeStatusLine
{
	my ($filename, $translated, $total, $byte_translated, $byte_total, $is_file) = @_;

	my $file = $filename;

	my @file_array;
	
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
	
	push(@file_array, $percentage);
	push(@file_array, $translated);
	push(@file_array, $total);
	push(@file_array, $byte_translated);
	push(@file_array, $byte_total);
	
	$file_status_hash{$filename} = [@file_array];
	
	return $file . $CLRF;
}

sub getCommonRouteStatus
{
	my @total = (0, 0, 0, 0, 0);
	my @top   = (@total);
	
	my $in_translated = 1;
	
	my @output;
	
	foreach my $file (@common_route_files)
	{
		if ($in_translated == 1 and $file_status_hash{$file}[0] == 0)
		{
			$in_translated = 0;
			@top = (@total);
			push(@output, "First untranslated file: " . $file . $CLRF);
		}
	
		for (my $i=1; $i < 5; $i++)
		{
			$total[$i] += $file_status_hash{$file}[$i];
		}
	}
	
	
	
	if ($top[1] > 0)
	{
		push(@output, makeStatusLine("translated common route", $top[1], $top[2], $top[3], $top[4], 0));
		push(@output, makeStatusLine("top vs total common route", $top[1], $total[2], $top[3], $total[4], 0));
	}
	
	push(@output, makeStatusLine("translated total common route", $total[1], $total[2], $total[3], $total[4], 0));
	
	push(@output, "Common route files:" . $CLRF);
	foreach my $file (@common_route_files)
	{
		push(@output, makeStatusLine($file, $file_status_hash{$file}[1], $file_status_hash{$file}[2], $file_status_hash{$file}[3], $file_status_hash{$file}[4], 0));
	}
	push(@output, $CLRF. $CLRF);
	
	return @output;
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
	
	$line_count = 0;
	$translated_line_count = 0;
	$byte_count = 0;
	$translated_byte_count = 0;
	
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
			
			push(@file_status, makeStatusLine("$file", $translated_line_count, $line_count, $translated_byte_count, $byte_count, 1));
				
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
			push(@group_status, makeStatusLine($group, $group_translated_lines, $group_lines, $group_translated_byte_count, $group_byte_count, 0));
			
			$total_lines                 += $group_lines;
			$total_translated_lines      += $group_translated_lines;
			$total_byte_count            += $group_byte_count;
			$total_translated_byte_count += $group_translated_byte_count;
			
			$group_lines = 0;
			$group_translated_lines = 0;
			$group_byte_count = 0;
			$group_translated_byte_count = 0;
			
			$group = substr($_, 14);
			
			last if $group eq "END";
		}
	}
	
	open FILE, ">", $status_file or die_local $!;
	
	print FILE "\t\t\tLINES\t\t\t\tBYTES" . $CLRF;
	print FILE "File\t\tpercentage\ttranslated\ttotal\t\tpercentage\ttranslated\ttotal" . $CLRF;
	
	print FILE makeStatusLine("TOTAL", $total_translated_lines, $total_lines, $total_translated_byte_count, $total_byte_count, 0);
	
	foreach (@group_status)
	{
		print FILE $_;
	}
	
	foreach (getCommonRouteStatus())
	{
		print FILE $_;
	}
	
	print FILE "All individual files: (even those already printed)" . $CLRF;
	
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
	if (-e $last_file_file)
	{
		handleFile(readFile($last_file_file));
	}
	loadFromScriptsInc;
}