#!/usr/bin/perl

use strict;
use warnings;

use File::Copy;

# setup options

my $make_widechar_copy = 1;

# add the original Japanese lines as comments
# turning this off will remove existing lines starting with #SCRIPT ORIGINAL
my $add_original_lines = 1;

# ignore the rest of the setup. It can't be used, but has to be there for the script to work
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
my $LINE_WIDTH = 700;

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
push(@common_route_files, "day/0204_karin1.txt");
push(@common_route_files, "day/0210_karin2.txt");
push(@common_route_files, "day/seiji2.txt");
push(@common_route_files, "day/suika2.txt");
push(@common_route_files, "day/seiji3.txt");
push(@common_route_files, "day/erocute.txt");
push(@common_route_files, "day/0225_ichigo1.txt");
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
push(@common_route_files, "day/king_game.txt");
push(@common_route_files, "day/zakuro4.txt");
push(@common_route_files, "day/seiji6.txt");
push(@common_route_files, "day/drink.txt");
push(@common_route_files, "day/yuzu4.txt");
push(@common_route_files, "day/fathers_day.txt");
push(@common_route_files, "day/zakuro5.txt");
push(@common_route_files, "day/tanabata.txt");
push(@common_route_files, "day/yuzu5.txt");
push(@common_route_files, "day/zakuro6.txt");
push(@common_route_files, "day/zakuro7.txt"); # due to fallthrough in zakuro6
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

my %status = (
	i => { # ichigo
		karada => [ "ep_ichigo_01", "ichigo_qa03", "ep_ichigo_06", "ichigo_qa08", "ep_ichigo_09", "ichigo_qa07", "ep_ichigo_10" ],
		atama  => [ "ep_ichigo_03", "ichigo_qa02", "ep_ichigo_05", "ichigo_qa04", "ichigo_qa05" , "ichigo_qa06", "ichigo_atama_1", "ichigo_atama_2", "ichigo_atama_3", "ichigo_atama_4" ],
		kokoro => [ "ep_ichigo_04", "ichigo_qa01", "ep_ichigo_08", "ichigo_qa09", "ep_ichigo_07", "ichigo_qa10", "ep_ichigo_02" ]
	},

	m => { # mikan
		karada => [ "ep_mikan_01", "mikan_qa10", "ep_mikan_06", "mikan_qa09", "ep_mikan_09", "mikan_qa05", "ep_mikan_10" ],
		atama  => [ "ep_mikan_03", "mikan_qa01", "ep_mikan_05", "mikan_qa03", "ep_mikan_11", "mikan_qa08", "mikan_qa04"  ],
		kokoro => [ "ep_mikan_04", "mikan_qa02", "ep_mikan_08", "mikan_qa06", "ep_mikan_07", "mikan_qa07", "ep_mikan_02" ]
	},
	
	k => { # karin
		karada => [ "ep_karin_01", "karin_qa02", "ep_karin_06", "karin_qa08", "ep_karin_09", "karin_qa09", "ep_karin_10" ],
		atama  => [ "ep_karin_03", "karin_qa06", "ep_karin_05", "karin_qa04", "karin_qa07", "karin_qa10" ],
		kokoro => [ "ep_karin_04", "karin_qa05", "ep_karin_08", "karin_qa01", "ep_karin_07", "karin_qa03", "ep_karin_02" ]
	}
);

my %status_labels = ();


foreach my $name (keys %status)
{
	foreach my $skill (keys %{$status{$name}})
	{
		for (my $i=0; $i < scalar @{$status{$name}{$skill}}; $i++)
		{
			$status_labels{$status{$name}{$skill}[$i]} = $name . $i . $skill;
		}
	}
}

my $TL_STATUS="";

my $is_status_group = 1;

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

my $text_dir = "text";
my $code_script_dir = "code_scripts";

my $empty = sprintf("%c%c", 0x81, 0x40);
my $star_prefix = sprintf("%c%c", 0x81, 0x99);
my $speaker_add = sprintf("%c%c", 0x81, 0x97);
my $period = sprintf("%c%c", 0x81, 0x44);
my $comma = sprintf("%c%c", 0x81, 0x43);
my $question_mark = sprintf("%c%c", 0x81, 0x48);
my $explanation_mark = sprintf("%c%c", 0x81, 0x49);

my @file_list;

my @japanese;
my $japanese_index;

my $line_count = 0;
my $translated_line_count = 0;
my $byte_count = 0;
my $translated_byte_count = 0;
my $byte_count_block = 0;

my $line_number = 0;

my $translated_all_lines = 0;
my $translated_all_bytes = 0;
my $translated_common_lines = 0;
my $translated_common_bytes = 0;

my $is_block_unreachable = 0;

my $next_line_translated = 0;

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

sub ConvertNamesToWide
{
	foreach my $key (keys %name_translation)
	{
		$name_translation{$key} = toWideChar($name_translation{$key});
	}
}

# there are empty names. Force them to be empty without throwing warnings or errors
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

sub getCharWidth
{
	my ($char) = @_;
	
	$char = toRegularChar($char);
	
	# return the width of the character
	# if a character isn't listed, then it is assumed to have the maximum known character width (30)
	# this appears to be the width of more or less all characters in the untranslated scripts
	# the translated will likely contain alpha-numberic and a few others
	# there is a risk that some narrow character is missed, but odds are that it will be rare enough to not really be noticed
	
	return 23 if $char eq "A";
	return 24 if $char eq "B";
	return 23 if $char eq "C";
	return 24 if $char eq "D";
	return 22 if $char eq "E";
	return 20 if $char eq "F";
	return 24 if $char eq "G";
	return 24 if $char eq "H";
	return 11 if $char eq "I";
	return 20 if $char eq "J";
	return 24 if $char eq "K";
	return 20 if $char eq "L";
	return 28 if $char eq "M";
	return 24 if $char eq "N";
	return 25 if $char eq "O";
	return 22 if $char eq "P";
	return 25 if $char eq "Q";
	return 24 if $char eq "R";
	return 23 if $char eq "S";
	return 20 if $char eq "T";
	return 24 if $char eq "U";
	return 23 if $char eq "V";
	return 29 if $char eq "W";
	return 21 if $char eq "X";
	return 21 if $char eq "Y";
	return 21 if $char eq "Z";
	
	return 19 if $char eq "a";
	return 20 if $char eq "b";
	return 19 if $char eq "c";
	return 20 if $char eq "d";
	return 19 if $char eq "e";
	return 12 if $char eq "f";
	return 19 if $char eq "g";
	return 20 if $char eq "h";
	return 11 if $char eq "i";
	return 11 if $char eq "j";
	return 19 if $char eq "k";
	return 11 if $char eq "l";
	return 28 if $char eq "m";
	return 20 if $char eq "n";
	return 20 if $char eq "o";
	return 20 if $char eq "p";
	return 20 if $char eq "q";
	return 14 if $char eq "r";
	return 19 if $char eq "s";
	return 13 if $char eq "t";
	return 20 if $char eq "u";
	return 17 if $char eq "v";
	return 24 if $char eq "w";
	return 18 if $char eq "x";
	return 17 if $char eq "y";
	return 17 if $char eq "z";
	
	return 22 if $char eq "0";
	return 22 if $char eq "1";
	return 22 if $char eq "2";
	return 22 if $char eq "3";
	return 22 if $char eq "4";
	return 22 if $char eq "5";
	return 22 if $char eq "6";
	return 22 if $char eq "7";
	return 22 if $char eq "8";
	return 22 if $char eq "9";
	
	return 21 if $char eq " ";
	return 21 if $char eq ".";
	return 21 if $char eq ",";
	return 17 if $char eq "'";
	
	# chars with 30 width: ?!-
	# those are intentionally skipped they would not change the return value anyway
	
	return 30;
}

my $empty_width = 21;

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
	
	die "undefined input for getType\n" if not defined $line;

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

sub toKanji
{
	my ($line) = @_;
	
	$line = convertLine($line);
	
	if (getType($line) ne "KANJI")
	{
		$line = $empty . $line;
	}
	
	return $line;
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
		$byte_count += $byte_count_block if $to_wide_char == 0;
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

	my @lines = ();
	
	foreach (@control_words)
	{
		if (index($text, $_) != -1)
		{
			return ($text);
		}
	}
	
	
	
	if (index($speaker, ",") != -1)
	{
		$speaker = substr($speaker, 0, index($speaker, ","));
	}
	
	my $word = "";
	my $word_width = 0;
	my $line = "";
	my $line_width = 0;
	
	my $print_debug_length = 0;
	
	my $line_count = 0;
	
	while (length $text > 0)
	{
		my $char = substr($text, 0, 1);
		$text = substr($text, 1);
		my $value = ord($char);
	
		if ($value >= 0x80)
		{
			$char = $char . substr($text, 0, 1);
			$text = substr($text, 1);
		}
		
		my $char_width = getCharWidth($char);
		
		if ($char eq $empty)
		{
			# append word to line
			if (($word_width + $line_width + $empty_width) < $LINE_WIDTH)
			{
				if ($line_width > 0)
				{
					$line = $line . $empty;
					$line_width = $line_width + $empty_width;
				}
				$line = $line . $word;
				$line_width = $line_width + $word_width;
			}
			else
			{
				if ($line_width > 0)
				{
					$line_count = $line_count + 1;
					if ($line_count == $NUM_LINES)
					{
						my $index = rindex($line, $period);
						
						if ($index == -1)
						{
							# no period in the line. Look for a comma to split on
							# presumably a comma is a better break than a random space
							$index = rindex($line, $comma);
						}
						
						if ($index != -1)
						{
							$index = $index + 2;
							$text = substr($line, $index) . $empty . $word . $empty . $text;
							$line = substr($line, 0, $index);
							$word = "";
							$word_width = 0;
						}
					}
					else
					{
						$line = $line . "<br>";
					}
					if ($line_width > 0)
					{
						push(@lines, $line);
						push(@lines, $line_width) if $print_debug_length > 0;
					}

				}
				if ($line_count == $NUM_LINES)
				{
					$line_count = 0;
					push(@lines, "");
					push(@lines, $speaker);
				}
				
				$line = $word;
				$line_width = $word_width;
			}
			$word = "";
			$word_width = 0;
		}
		else
		{
			$word = $word . $char;
			$word_width = $word_width + $char_width;
		}
	}
	
	if ($word_width > 0)
	{
		if (($word_width + $line_width + $empty_width) < $LINE_WIDTH)
		{
			if ($line_width > 0)
			{
				$line = $line . $empty;
				$line_width = $line_width + $empty_width;
			}
			$line = $line . $word;
			$line_width = $line_width + $word_width;
		}
		else
		{
			$line_count = $line_count + 1;
			if ($line_count == $NUM_LINES)
			{
				my $index = rindex($line, $period);
				if ($index == -1)
				{
					$index = rindex($line, $comma);
				}
				if ($index != -1)
				{
					$index = $index + 2;
					$word = substr($line, $index) . $empty . $word;
					$line = substr($line, 0, $index);
				}
			}
			else
			{
				$line = $line . "<br>";
			}
			if ($line_width > 0)
			{
				push(@lines, $line);
				push(@lines, $line_width) if $print_debug_length > 0;
			}
			$line = $word;
			$line_width = $word_width;
			if ($line_count == $NUM_LINES)
			{
				$line_count = 0;
				push(@lines, "");
				push(@lines, $speaker);
			}
		}
	}
	
	if ($line_width > 0)
	{
		push(@lines, $line);
		push(@lines, $line_width) if $print_debug_length > 0;
	}
	
	return @lines;
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
	
	# add the original lines as comments
	foreach (@jap_lines)
	{
		push(@output, "#SCRIPT ORIGINAL " . $_) if $add_original_lines;
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
	
	
	# print Japanese lines if no translation has been found
	if ($has_japanese == 1 and $has_translation != 1)
	{
		foreach (@jap_lines)
		{
			push(@lines, $_);
		}
	}
	
	if ($type eq "SPEAKER" and (scalar @lines )< 2)
	{
		print "Speaker without text at line " . $line_number . " (estimated)\n";
		foreach (@input)
		{
			print $_ . "\n";
		}
		die_local
	}
	
	if (scalar @lines > 0 and getType($lines[0]) eq "TEXT")
	{
		# kanji line starting with text
		# inset a kanji whitespace
		$lines[0] = $empty . $lines[0];
	}
	
	$line_count++ if ($count_this_line == 1 and $to_wide_char == 0);
	
	# debug code
	#push(@lines, "has translation: " . $has_translation);
	
	if ($next_line_translated == 1)
	{
		$next_line_translated = 0;
		$has_translation = 1;
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
			die_local;
		}
	
		if ($count_this_line == 1 and $to_wide_char == 0)
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
	elsif ($is_block_unreachable == 0)
	{
		push(@output, "#SCRIPT UNTRANSLATED");
		push(@output, "##SCRIPT NEXT LINE TRANSLATED");
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
	
	my $index = rindex($file, "/");
	my $filename = substr($file, $index+1) if $index != -1;
	$index = rindex($filename, "\\");
	$filename = substr($filename, $index+1) if $index != -1;
	
	return if ($filename ne "shop_buy.txt" and $filename ne "shop_sel.txt");
	
	print "Generating " . $filename . "\n";
	
	# use byte values for Subuta-san's names as that will keep the script working in the ASCII area and avoid charset issues.
	my $to_name   = $speaker_add . $name_translation{sprintf( "%c%c%c%c%c%c%c%c", 147, 88,  136, 245, 130, 179, 130, 241)};
	my $from_name = $speaker_add . $name_translation{sprintf( "%c%c%c%c%c%c%c%c", 145, 131, 138, 87,  130, 179, 130, 241)};
	
	if ($to_wide_char == 1)
	{
		$from_name = toWideChar($from_name);
		$to_name = toWideChar($to_name);
	}

	my $name_length = length $from_name;
	
	my $out_file = substr($file, 0, rindex($file, ".")) . "_unnamed.txt";
	
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
	
	push(@file_list, $file);
	
	$japanese_index = -1;
	
	@japanese = readFile("../original/" . $file);
	my @translated = readFile($file);
	
	my @output;
	my @output_wide;
	
	my $last_was_blank = 0;
	my $dialogue_added = 0;
	my $script_ignore = 0;
	my $added_button = 0;
	
	my $label_translated = 0;
	my $label_total = 0;
	my $last_label = "";
	
	$next_line_translated = 0;
	$is_block_unreachable = 0;
	
	my $backup_line_count            = 0;
	my $backup_translated_line_count = 0;
	my $backup_byte_count            = 0;
	my $backup_translated_byte_count = 0;
	
	for ($line_number =0; $line_number < scalar @translated; $line_number++)
	{
		my $line = $translated[$line_number];
		my $type = getType($line);
		my $add_kanji_to_text = 0; 
		
		# handle TL notes
		if ($type eq "TEXT") 
		{
			if (substr($line, 0, 29) eq "setbutton 2,18,220,0,\"TLnotes")
			{
				push(@output, $line);
				push(@output_wide, $line);
				$added_button = 1;
				$last_was_blank = 0;
				next;
			}
			if ($added_button and substr($line, 0, 11) eq "clearbutton")
			{
				push(@output, $line);
				push(@output_wide, $line);
				$added_button = 0;
				$last_was_blank = 0;
				next;
			}
		}
		
		
		if ($script_ignore or $line eq 'skip_untranslated_training=0' or $line eq 'if skip_untranslated_training=1 then return' or $line eq '@remove_this_line_when_translating')
		{
			push(@output, $line);
			push(@output_wide, $line);
			$script_ignore = 0 if ($line eq "#SCRIPT IGNORE END");
			if (substr($line, 0, 27) eq "#SCRIPT SKIP JAPANESE LINES")
			{
				my $num_lines_skipped = substr($line, 27);
				for (my $i=0; $i < $num_lines_skipped; $i++)
				{
					getNextJapType();
				}
			}
			next;
		}
		
		if ($type eq "BLANK")
		{
			if ($last_was_blank == 0)
			{
				push(@output, $line);
				push(@output_wide, $line);
			}
			$last_was_blank = 1;
			next;
		}
		
		$last_was_blank = 0;
		
		if ($type eq "COMMENT")
		{
			next if (substr($line, 0, 16) eq "#SCRIPT ORIGINAL");
			next if (substr($line, 0, 20) eq "#SCRIPT UNTRANSLATED");
			next if (substr($line, 0, 29) eq "##SCRIPT NEXT LINE TRANSLATED");
			
			push(@output, $line);
			push(@output_wide, $line);
			
			if ($line eq "#SCRIPT ADD DIALOGUE")
			{
				$dialogue_added = $allow_new_dialogue;
			}
			elsif ($line eq "#SCRIPT IGNORE")
			{
				$script_ignore = 1;
			}
			elsif (substr($line, 0, 9) eq "#TLSTATUS")
			{
				$TL_STATUS=substr($line, 10);
			}
			elsif (substr($line, 0, 19) eq "#SCRIPT UNREACHABLE")
			{
				$is_block_unreachable = 1;
				# backup numbers
				$backup_line_count            = $line_count;
				$backup_translated_line_count = $translated_line_count;
				$backup_byte_count            = $byte_count;
				$backup_translated_byte_count = $translated_byte_count;
			}
			elsif (substr($line, 0, 28) eq "#SCRIPT NEXT LINE TRANSLATED")
			{
				$next_line_translated = 1;
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
			
			$to_wide_char = 0;
			$split_lines = 0;
			
			# remove old style unmarked original text as comments
			#my @temp_lines = handleScreenLines($dialogue_added, @lines);			
			#foreach (@temp_lines)
			#{
			#	last if (substr($_, 0, 1) ne "#");
			#	my $temp_str = "#" . substr($_, 17);
			#	if ($temp_str eq $output[-1])
			#	{
			#		pop(@output);
			#	}
			#}
			
			foreach((handleScreenLines($dialogue_added, @lines)))
			{
				push(@output, $_);
			}
			
			$to_wide_char = 1;
			$split_lines = 1;
			
			if ($make_widechar_copy == 1)
			{
				foreach((handleScreenLines($dialogue_added, @lines)))
				{
					push(@output_wide, $_);
				}
			}
			$last_was_blank = 1;
			$dialogue_added = 0;
			$line_number--; # prevent deleting comments
			next;
		}
		
		
		$dialogue_added = 0;
		
		if ($type eq "TEXT" and index($line, "select") != -1)
		{
			push(@output, "#SCRIPT ORIGINAL " . $japanese[$japanese_index]);
			my $temp_line = substr($line, index($line, "select") + 6);
			$temp_line = removeLeadingWhitespace($temp_line);
			if (substr($temp_line, 0, 3) eq "sel")
			{
				my $orig_option_count = $japanese[$japanese_index] =~ tr/\"//;
				my $translated_option_count = $line =~ tr/\"//;
			
				if ($orig_option_count != $translated_option_count)
				{
					print "Wrong number of \" for selection in file " . $file . "\n";
					print "Japanese has " . $orig_option_count . " while the translation has " . $translated_option_count . "\n";
					print "Faulty line " . "	" . ($line_number + 1) . "	" .  $line . "\n";
			
					exit();
				}
				
			
				$line_count++;
				if ($line ne $japanese[$japanese_index])
				{
					$translated_line_count++;
				}
				push(@output, $line);
				push(@output_wide, $line);
				next;
			}
		}
		
		if (substr($japanese[$japanese_index], 0, 12) eq "screen_flash" and index($line, "screen_flash") != -1)
		{
			push(@output, "if _TRANSLATOR_OPTION_DISABLE_FLASHES=0 then " . $japanese[$japanese_index]);
			push(@output_wide, "if _TRANSLATOR_OPTION_DISABLE_FLASHES=0 then " . $japanese[$japanese_index]);
			
			next;
		}
		
		if ($line ne $japanese[$japanese_index])
		{
			my $mismatch = 1;
					
			# handle if then (translated text)
			if (substr($line, 0, 2) eq "if" and substr($japanese[$japanese_index], 0, 2) eq "if")
			{
				my $offset = index($japanese[$japanese_index], "then");
				if ($offset != -1)
				{
					$offset = $offset + 4;
					if (substr($line, 0, $offset) eq substr($japanese[$japanese_index], 0, $offset))
					{
						if (getType(removeLeadingWhitespace(substr($japanese[$japanese_index], $offset))) eq "KANJI")
						{
							$line = substr($line, 0, $offset) . " " . toKanji(removeLeadingWhitespace(substr($line, $offset)));
							$mismatch = 0;
						}
					}
				}
			}
					
			if ($mismatch == 1)
			{
				print "mismatched lines in " . $file . "\n";
				print "expected " . "	" . ($japanese_index + 1) . "	" .  $japanese[$japanese_index] . "\n";
				print "found    " . "	" . ($line_number + 1) . "	" .  $line . "\n";
			
				exit();
			}
		}
		
		push(@output, $line);
		push(@output_wide, $line);
		
		if (substr($line, 0, 5) eq "label")
		{
			if ($is_block_unreachable == 1)
			{
				$is_block_unreachable = 0;
				# restore backup
				$line_count            = $backup_line_count;
				$translated_line_count = $backup_translated_line_count;
				$byte_count            = $backup_byte_count;
				$translated_byte_count = $backup_translated_byte_count;
			}
		
			my $label_string = removeTrailingWhitespace(substr($line, 5));
			
			if ($is_status_group)
			{
				my $local_translated = $translated_line_count - $label_translated;
				my $local_total = $line_count - $label_total;
				if (($local_translated * 2) > $local_total and exists $status_labels{$last_label})
				{
					my $label_key   = $status_labels{$last_label};
					my $label_name  = substr($label_key, 0, 1);
					my $label_index = substr($label_key, 1, 1);
					my $label_stat  = substr($label_key, 2);
					${$status{$label_name}{$label_stat}}[$label_index] = "";
				}
				$label_translated = $translated_line_count;
				$label_total = $line_count;
				$last_label = $label_string;
			}
			
			if ($add_label_text == 1)
			{
				$label_string = "label " . $label_string;
				$label_string = toWideChar($label_string);
				push(@output, "");
				push(@output, $label_string);
				push(@output, "");
			}
		}
	}
	
	if ($is_block_unreachable == 1)
	{
		$is_block_unreachable = 0;
		# restore backup
		$line_count            = $backup_line_count;
		$translated_line_count = $backup_translated_line_count;
		$byte_count            = $backup_byte_count;
		$translated_byte_count = $backup_translated_byte_count;
	}
	
	# ensure last label is also included
	if ($is_status_group)
	{
		my $local_translated = $translated_line_count - $label_translated;
		my $local_total = $line_count - $label_total;
		if (($local_translated * 2) > $local_total and exists $status_labels{$last_label})
		{
			my $label_key   = $status_labels{$last_label};
			my $label_name  = substr($label_key, 0, 1);
			my $label_index = substr($label_key, 1, 1);
			my $label_stat  = substr($label_key, 2);
			${$status{$label_name}{$label_stat}}[$label_index] = "";
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
	
	my $file_wide = "../musume/scripts/" . $file;
	if ($make_widechar_copy == 1 and -e $file_wide)
	{
		open FILE, ">", $file_wide or die_local $!;
	
		foreach (@output_wide)
		{
			print FILE $_ . $CLRF;
		}
		close FILE;
		makeUnnamedShop($file_wide);
	}
	
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
		use bigint;
		$percentage = (10000 * $byte_translated) / $byte_total;
	}
	
	$file = $file . $percentage . "\t" . $byte_translated . "\t" . $byte_total;
	
	push(@file_array, $percentage);
	push(@file_array, $translated);
	push(@file_array, $total);
	push(@file_array, $byte_translated);
	push(@file_array, $byte_total);
	
	$file_status_hash{$filename} = [@file_array] if $is_file == 1;
	
	if ($TL_STATUS ne "")
	{
		$file = $file . "\t\t" . $TL_STATUS;
	}
	
	return $file . $CLRF;
}

sub getAllReachable
{
	my ($translated_lines, $byte_translated) = @_;
	
	my @total = (0, $translated_lines, 0, $byte_translated, 0);
	
	foreach my $file (@file_list)
	{
		$total[2] += $file_status_hash{$file}[2];
		$total[4] += $file_status_hash{$file}[4];
		
		if (substr($file, 0, 8) eq "training")
		{
			if ($file eq "training/training_in.txt" or $file eq "training/training_mikan_01.txt")
			{
				# already part of common route. Don't count twice.
				next;
			}
		}
		elsif (substr($file, 0, 6) ne "status" and substr($file, 0, 4) ne "item")
		{
			next;
		}
		
		# shop, training or status. Assume those files to be reachable from start.
		
		$total[1] += $file_status_hash{$file}[1];
		$total[3] += $file_status_hash{$file}[3];
	}
	
	$translated_all_lines = $total[1] / $total[2];
	$translated_all_bytes = $total[3] / $total[4];
	
	return makeStatusLine("All reachable", $total[1], $total[2], $total[3], $total[4], 0);
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
		$translated_common_lines = $top[1] / $total[2];
		$translated_common_bytes = $top[3] / $total[4];
	}
	else
	{
		# looks like all files are translated. We assume top to contain the files reachable from start, which would now be all of them
		@top = (@total);
	}
	
	unshift(@output, getAllReachable($top[1], $top[3]));
	
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
	$TL_STATUS="";

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
	
	my @groups;
	my %group_stats = ();

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
			
			$TL_STATUS="";
		}
		elsif (substr($_, 0, 13) eq "#SCRIPT GROUP")
		{
			push(@group_status, makeStatusLine($group, $group_translated_lines, $group_lines, $group_translated_byte_count, $group_byte_count, 0));
			
			push(@groups, $group);
			$group_stats{$group} = [ $group_translated_lines, $group_lines, $group_translated_byte_count, $group_byte_count ];
			
			$total_lines                 += $group_lines;
			$total_translated_lines      += $group_translated_lines;
			$total_byte_count            += $group_byte_count;
			$total_translated_byte_count += $group_translated_byte_count;
			
			$group_lines = 0;
			$group_translated_lines = 0;
			$group_byte_count = 0;
			$group_translated_byte_count = 0;
			
			$group = substr($_, 14);
			$is_status_group = 0 if $group eq "prologue";
			
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
	
	print FILE $CLRF . $CLRF . "Status episodes" . $CLRF;
	print FILE "\tIchigo\tMikan\tKarin" . $CLRF;
	foreach my $skill ("karada", "kokoro","atama")
	{
		print FILE $skill;
		foreach my $name ("i", "m", "k")
		{
			my $i = 0;
			while ((scalar @{$status{$name}{$skill}}) > $i)
			{
				last if $status{$name}{$skill}[$i] ne "";
				$i ++;
			}
			print FILE "\t" . $i;
			
		}
		print FILE $CLRF;
	}
	
	print FILE "Next file" . $CLRF;
	foreach my $skill ("karada", "kokoro","atama")
	{
		print FILE $skill;
		foreach my $name ("i", "m", "k")
		{
			my $i = 0;
			while ((scalar @{$status{$name}{$skill}}) > $i)
			{
				last if $status{$name}{$skill}[$i] ne "";
				$i ++;
			}
			print FILE "\t";
			print FILE $status{$name}{$skill}[$i] if ((scalar @{$status{$name}{$skill}}) > $i);
			
		}
		print FILE $CLRF;
	}
	
	close FILE;
	
	open FILE, ">", "../translation_status_human_readable.txt" or die_local $!;
	
	print FILE "Translation Progress (autogenerated)" . $CLRF . $CLRF;
	print FILE "The counting is done in both lines and bytes. Bytes might be the best as it avoids the error caused by short and long lines. ";
	print FILE "Common for both is that they only count actual onscreen text. This excludes untranslateable lines in the script like control for sprites and bgm. ";
	print FILE "Unreviewed lines are made by people on HongFire, who has left long ago. Quality varies greatly and some, but certainly not all, can be used." . $CLRF . $CLRF;
	
	
	print FILE "Common route:" . $CLRF;
	print FILE "DONE!" . $CLRF;
	
	print FILE $CLRF;
	print FILE "Total: (reviewed, reachable without going through untranslated sections)" . $CLRF;
	print FILE "Lines: " . sprintf("%.3f", $translated_all_lines*100) . "%" . $CLRF;
	print FILE "Bytes: " . sprintf("%.3f", $translated_all_bytes*100) . "%" . $CLRF;
	
	print FILE $CLRF;
	print FILE "Total: (including unreviewed and unlockable content)" . $CLRF;
	print FILE "Lines: " . sprintf("%.3f", ($total_translated_lines / $total_lines)*100) . "%" . $CLRF;
	print FILE "Bytes: " . sprintf("%.3f", ($total_translated_byte_count / $total_byte_count)*100) . "%" . $CLRF;
	
	print FILE $CLRF;
	print FILE "Total line count: ". $total_lines . $CLRF;
	print FILE "Total byte count: ". $total_byte_count . $CLRF;
	
	print FILE $CLRF;
	print FILE "Stats for each file group:" . $CLRF;
	print FILE "See scripts.ini for which files belong to which group." . $CLRF;
	
	print FILE $CLRF;
	print FILE "Completed groups:" . $CLRF;
	
	foreach my $group (@groups)
	{
		next if $group_stats{$group}[0] < 10;
		next if $group_stats{$group}[0] != $group_stats{$group}[1];
	
		print FILE $group . $CLRF;
	}
	
	print FILE $CLRF;
	print FILE "Incomplete groups:" . $CLRF;
	
	foreach my $group (@groups)
	{
		next if $group_stats{$group}[0] < 10;
		next if $group_stats{$group}[0] == $group_stats{$group}[1];
	
		print FILE $CLRF;
		print FILE "Group: " . $group . $CLRF;
		print FILE "Lines: " . sprintf("%.3f", ($group_stats{$group}[0] / $group_stats{$group}[1])*100) . "%" . $CLRF;
		print FILE "Bytes: " . sprintf("%.3f", ($group_stats{$group}[2] / $group_stats{$group}[3])*100) . "%" . $CLRF;
	}
	
	close FILE;
}

sub convertForewords
{
	print "Generating widechar version of TL forewords";
	my @wide;
	
	my $state = 0;
	my $speaker;
	
	$to_wide_char = 1;
	$split_lines = 1;
	
	foreach (readFile("translator_intro.txt"))
	{
		my $type = getType($_);
		if ($type eq "SPEAKER")
		{
			$speaker = convertLine($_);
			push(@wide, $speaker);
			$state = 1;
		}
		elsif ($state == 1)
		{
			my $text = convertLine($_);
			foreach((splitLine($speaker, $text)))
			{
				push(@wide, $_);
			}
			$state = 0;
		}
		else
		{
			push(@wide, $_);
		}
	}
	
	open FILE, ">../musume/scripts/translator_intro.txt" or die_local $!;
	
	foreach (@wide)
	{
		print FILE $_ . $CLRF;
	}
	close FILE;
}

sub CopyDir
{
	my ($source, $dest) = @_;
	
	mkdir $dest unless (-e $dest);
	
	opendir DIR, $source or die "cannot open dir $source: $!";
	my @files= readdir DIR;
	closedir DIR;
	
	foreach (@files)
	{
		next if substr($_, 0, 1) eq ".";
		my $file = $source . "/" . $_;
		my $dest_file = $dest . "/" . $_;
		if (-d $file)
		{
			CopyDir($file, $dest_file);
		}
		else
		{
			copy($file, $dest_file);
		}
	}
}

sub CopyToGame
{
	chdir "..";
	die "path to game.txt not found" unless (-e "path to game.txt");
	open my $handle, '<', "path to game.txt";
	chomp(my @lines = <$handle>);
	close $handle;
	
	my $path = shift @lines;
	
	die $path . " not found" unless (-e $path);
	die "Game not found" unless (-e $path . "/taskforce.xml");
	print "Copying files to " . $path . "\n";
	
	CopyDir("musume",  $path . "/musume");
	
	copy("taskforce.xml", $path . "/taskforce.xml");
	
}

sub BuildFile
{
    my $target = shift;
	my $file = shift;
	my $source = shift;

	my $source_file = $source . "/" . $file;

	my $target_file = $text_dir . "/" . $file;
    
    my $dir = substr($target_file, 0, rindex($target_file, "/"));
    mkdir $dir unless (-e $dir);
	
	open OUTPUT_FILE, ">", $target_file or die $!;
	
	my $index_counter = 0;
	my $state = 0;
	
	foreach my $line (readFile($source_file))
	{
		if (substr($line, 0, 5) eq "label")
		{
			my $label = substr($line, 6);
			my $rindex = index($label, " ");
			$label = substr($label, 0, $rindex) if ($rindex != -1);
			$rindex = index($label, "\t");
			$label = substr($label, 0, $rindex) if ($rindex != -1);
			print OUTPUT_FILE "#label ";
			print OUTPUT_FILE $label;
			print OUTPUT_FILE $CLRF;
			print OUTPUT_FILE $CLRF;
			
			#$index_counter = 0;
		}
		else
		{
			my $type = getType($line);
            if ($type eq "SPEAKER" or $type eq "KANJI")
            {
                if ($state == 0)
                {
                    $index_counter++;
                    print OUTPUT_FILE "##INDEX $target ";
                    print OUTPUT_FILE $index_counter;
                    print OUTPUT_FILE $CLRF;
					if ($type eq "SPEAKER")
					{
						print OUTPUT_FILE "##TYPE SPEAKER";
					}
					else
					{
						print OUTPUT_FILE "##TYPE TEXT";
					}
					print OUTPUT_FILE $CLRF;
                }
                $state = 1;
                print OUTPUT_FILE "#";
                print OUTPUT_FILE $line;
                print OUTPUT_FILE $CLRF;
            }
            elsif ($state == 1)
            {
                $state = 0;
                print OUTPUT_FILE $CLRF;
            }
            elsif ($type eq "TEXT" and (index($line, "select ") != -1 or index($line, "select\t") != -1))
            {
                $index_counter++;
                print OUTPUT_FILE "##INDEX $target ";
                print OUTPUT_FILE $index_counter;
                print OUTPUT_FILE $CLRF;
                print OUTPUT_FILE "##TYPE SELECT";
                print OUTPUT_FILE $CLRF;
                print OUTPUT_FILE "#";
                print OUTPUT_FILE $line;
                print OUTPUT_FILE $CLRF;
                print OUTPUT_FILE $CLRF;
            }
            elsif ($type eq "TEXT" and index($line, "select_icon_add") != -1)
            {
                my $index = index($line, "select_icon_add");
                my $print_line = substr($line, $index);
                $print_line = substr($print_line, 0, rindex($print_line, "\"")+1);
                
                $index_counter++;
                print OUTPUT_FILE "##INDEX $target ";
                print OUTPUT_FILE $index_counter;
                print OUTPUT_FILE $CLRF;
                print OUTPUT_FILE "##TYPE BUTTON";
                print OUTPUT_FILE $CLRF;
                print OUTPUT_FILE "#";
                print OUTPUT_FILE $print_line;
                print OUTPUT_FILE $CLRF;
				
				$print_line = substr($print_line, 0, rindex($print_line, "\""));
				$print_line = substr($print_line, 1+ rindex($print_line, "\""));
				print OUTPUT_FILE $print_line;
                print OUTPUT_FILE $CLRF;
				
                print OUTPUT_FILE $CLRF;
            }
            
		}
	}
	
	close OUTPUT_FILE;
}

sub StartBuild
{
	my $source = shift;

	chdir("..");
    mkdir $text_dir unless (-e $text_dir);
    
    foreach ("scripts\\prologue\\youzyo.txt", "scripts\\training\\training_mikan_02.txt")
    #foreach (readFile($source . "/scripts.ini"))
    {
        if (substr($_, 0, 7) eq "scripts")
        {
            my $file = substr($_, 8);
            $file =~ s/\\/\//g;
            BuildFile("ORIGINAL",  $file, $source);
        }
    }
}

sub InsertFile
{
	my $file = shift;
	
	my $code_file = $code_script_dir . "/" . $file;
	
	my $dir = substr($code_file, 0, rindex($code_file, "/"));
    mkdir $dir unless (-e $dir);

    my @scriptFile = readFile("scripts/" . $file);
	my @textFile = readFile($text_dir . "/" . $file);
	my @codeFile = ();
	
	open OUTPUT_FILE, ">", ($text_dir . "/" . $file) or die $!;
	
	while (exists $textFile[0])
	{
		my $speaker_line = "";
		my $line = shift(@textFile);
		print OUTPUT_FILE $line;
		print OUTPUT_FILE $CLRF;
		
		if (substr($line,0, 16) eq "##INDEX ORIGINAL")
		{
			my $index_line = $line;
		
			#my @block = ();
			while (substr($line, 0, 6) ne "##TYPE")
			{
				$line = shift(@textFile);
				print OUTPUT_FILE $line;
				print OUTPUT_FILE $CLRF;
			}
			
			my $type = substr($line, 7);
			
			if ($type eq "SELECT")
			{
				$line = shift(@textFile);
				print OUTPUT_FILE $line;
				print OUTPUT_FILE $CLRF;
				
				my $select_line = substr($line, 1, index($line, "\""));
				while (1)
				{
					$line = shift(@scriptFile);
					push(@codeFile, $line);
					next if substr($line, 0, 1) eq "#";
					next if index($line, $select_line);
					last;
				}
				
				pop(@codeFile);
				my $temp_line = pop(@codeFile);
				push(@codeFile, $index_line);
				push(@codeFile, substr($temp_line, 17));
				
				my @options = split "\"", $line;
				foreach (@options)
				{
					next if index($_, ",") != -1;
					print OUTPUT_FILE $_;
					print OUTPUT_FILE $CLRF;
				}
			}
			elsif ($type eq "SPEAKER")
			{
				while (1)
				{
					my $local_line = shift(@scriptFile);
					push(@codeFile, $local_line);
					last if substr($local_line, 0, 2) eq $speaker_add;
				}
				pop(@codeFile);
			}
			elsif ($type eq "TEXT")
			{
				while (1)
				{
					my $local_line = shift(@scriptFile);
					last if substr($local_line, 0, 16) eq "#SCRIPT ORIGINAL";
				}
				
			}
			
			if ($type eq "TEXT" or $type eq "SPEAKER")
			{
				while (getType($scriptFile[0]) ne "KANJI" and getType($scriptFile[0]) ne "TEXT")
				{
					my $local_line = shift(@scriptFile);
					push(@codeFile, $local_line);

				}
				while (1)
				{
					my $temp_line = pop(@codeFile);
					next if substr($temp_line, 0, 1) eq "#";
					push(@codeFile, $temp_line);
					last;
				}
				push(@codeFile, $index_line);
			
				while (substr($textFile[0], 0, 1) eq "#")
				{
					$line = shift(@textFile);
					print OUTPUT_FILE $line;
					print OUTPUT_FILE $CLRF;
					
					push(@codeFile, substr($line, 1)) if substr($line, 0, 3) eq ("#" . $speaker_add);
				}
			
				while (getType($scriptFile[0]) eq "KANJI" or getType($scriptFile[0]) eq "TEXT")
				{
					my $local_line = shift(@scriptFile);
					print OUTPUT_FILE $local_line;
					print OUTPUT_FILE $CLRF;
				}
			}
		}
	}
	
	while (exists $scriptFile[0])
	{
		my $local_line = shift(@scriptFile);
		push(@codeFile, $local_line);
	}
	
	close OUTPUT_FILE;
	
	open OUTPUT_FILE, ">", $code_file or die $!;
	foreach (@codeFile)
	{
		print OUTPUT_FILE $_;
		print OUTPUT_FILE $CLRF;
	}
	close OUTPUT_FILE;
}

sub StartInsert
{
	chdir("..");
    mkdir $text_dir unless (-e $text_dir);
	mkdir $code_script_dir unless (-e $code_script_dir);
    
    foreach ("scripts\\prologue\\youzyo.txt", "scripts\\training\\training_mikan_02.txt")
    #foreach (readFile("original/scripts.ini"))
    {
        if (substr($_, 0, 7) eq "scripts")
        {
            my $file = substr($_, 8);
            $file =~ s/\\/\//g;
            InsertFile($file);
        }
    }
}

sub TranslateNames
{
	my $file = shift;

	my @textFile = readFile($file);
	
	my @output = ();
	
	while (exists $textFile[0])
	{
		my $line = shift(@textFile);
	
		next if (substr($line, 0, 19) eq "##Translated name: ");
		if (substr($line, 0, 3) eq ("#") . $speaker_add)
		{
			my $japanese_name = substr($line, 3);
			if (index($japanese_name, ",") != -1)
			{
				$japanese_name = substr($japanese_name, 0, index($japanese_name, ","));
			}
			my $translated_name = $name_translation{$japanese_name};
			
			push(@output, "##Translated name: ");
			push(@output, $translated_name);
			push(@output, $CLRF);
		}
		push(@output, $line);
		push(@output, $CLRF);
	}
	
	open OUTPUT_FILE, ">", ($file) or die $!;
	foreach (@output)
	{
		print OUTPUT_FILE $_;
	}
	close OUTPUT_FILE;
}

sub StartTranslateNames
{
	chdir("../" . $text_dir);
    
    foreach ("scripts\\prologue\\youzyo.txt", "scripts\\training\\training_mikan_02.txt")
    #foreach (readFile("original/scripts.ini"))
    {
        if (substr($_, 0, 7) eq "scripts")
        {
            my $file = substr($_, 8);
            $file =~ s/\\/\//g;
            TranslateNames($file);
        }
    }
}

sub MergeFile
{
	my $file            = shift;
	my $source_text_dir = shift;
	my $source_code_dir = shift;
    my $dest_dir        = shift;
	my $version         = shift;
	
	print "Merging files: " . $file . "\n";
	
	my $text_file = $source_text_dir . "/" . $file;
	my $code_file = $source_code_dir . "/" . $file;
	my $dest_file = $dest_dir        . "/" . $file;
	my $trigger   = "##INDEX " . $version . " ";
	
	my $trigger_length = length($trigger);
	
	my @text = readFile($text_file);
	my @code = readFile($code_file);


	open OUTPUT_FILE, ">", ($dest_file) or die $!;
	while (exists $code[0])
	{
		my $line = shift(@code);
		
		if (substr($line, 0, $trigger_length) ne $trigger)
		{
			print OUTPUT_FILE $line;
			print OUTPUT_FILE $CLRF;
			next;
		}
		
		## merge in text/translation

		# forward to the same index in text
		# note: this requires text to be in the same order in both files
		while (1)
		{
			my $temp_line = shift(@text);
			last if $temp_line eq $line;
		}
		
		my $type = shift(@text);
		$type = substr($type, 7);
		
		while (substr($text[0], 0, 1) eq "#")
		{
			shift(@text);
		}
		
		# currently, both @text and @code have been forwarded to have the text as the next line
		# also the type has been read. What's left now is to branch based on type and do the actual merge
		
		if ($type eq "SELECT")
		{
			$line = shift(@code);
			$line = substr($line, 0, index($line, "#")) if index($line, "#") != -1;
			
			
			my $index = index($line, "\"");
			my $front_line = substr($line, 0, $index);
			$front_line = substr($front_line, 0, index($front_line, ","));
			print OUTPUT_FILE $front_line;
			$line = substr($line, $index);
			
			while (index($line, "\"") != -1)
			{
				$line = substr($line, index($line, "\"")+1);
				$line = substr($line, index($line, "\"")+1);
				
				my $answer = shift(@text);
				die "Select answers can't contain \"\n" if index($answer, "\"") != -1;
				die "Too few answers for select\n" if getType($answer) eq "BLANK";
				print OUTPUT_FILE ",\"";
				print OUTPUT_FILE $answer;
				print OUTPUT_FILE "\"";
				
			}
			print OUTPUT_FILE $CLRF;
		}
		elsif ($type eq "SPEAKER")
		{
			my $speaker_line = shift(@code);
			my $speaker = substr($speaker_line, 2);
			my $voice = undef;
			
			($speaker, $voice) = split(",", $speaker);
			
			$speaker = $name_translation{$speaker};
			
			$speaker_line = $speaker_add . $speaker;
			$speaker_line .= ("," . $voice) if defined $voice;
			
			# print the speaker line
			print OUTPUT_FILE $speaker_line;
			print OUTPUT_FILE $CLRF;
			
			# handle the actual text
			my $translated_text = shift(@text);
			foreach (splitLine($speaker_line, toWideChar($translated_text)))
			{
				print OUTPUT_FILE $_;
				print OUTPUT_FILE $CLRF;
			}
		}
		elsif ($type eq "TEXT")
		{
			my $translated_text = shift(@text);
			foreach (splitLine("", toWideChar($translated_text)))
			{
				print OUTPUT_FILE $_;
				print OUTPUT_FILE $CLRF;
			}
		}
		else
		{
			die ("Type " . $type . " unknown\n");
		}
	}
	
	
	close OUTPUT_FILE;
}


sub StartMerge
{
	chdir("..");
	
	ConvertNamesToWide();
    
	my $source_text_dir = $text_dir;
	my $source_code_dir = $code_script_dir;
    my $dest_dir        = "musume/scripts";
	my $version         = "ORIGINAL";
	
    foreach ("scripts\\prologue\\youzyo.txt", "scripts\\training\\training_mikan_02.txt")
    #foreach (readFile("original/scripts.ini"))
    {
        if (substr($_, 0, 7) eq "scripts")
        {
            my $file = substr($_, 8);
            $file =~ s/\\/\//g;
            MergeFile($file, $source_text_dir, $source_code_dir, $dest_dir, $version);
        }
    }
}

if ($#ARGV >= 0)
{
    if ($ARGV[0] eq "build")
    {
		# arguments
		# 1 build
		# 2 path to scripts
        StartBuild $ARGV[1];
    }
	elsif ($ARGV[0] eq "insert")
	{
		# inserts already translated lines into text
		StartInsert
	}
	elsif ($ARGV[0] eq "names")
	{
		# updates the line, which tells which will be used in the translation
		StartTranslateNames
	}
	elsif ($ARGV[0] eq "merge")
	{
		# merge files into playable files
		StartMerge
	}
    else
    {
        handleFile $ARGV[0];
    }
}
else
{
	if (-e $last_file_file)
	{
		handleFile(readFile($last_file_file));
	}
	CopyDir(".", "../musume/scripts") if $make_widechar_copy == 1;
	loadFromScriptsInc;
	convertForewords if $make_widechar_copy == 1;
	CopyToGame;
}