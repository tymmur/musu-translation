#!/usr/bin/perl

# script to modify taskforce into getting translated strings in schedule
# the strings are set inside this script
# the untranslated strings are present (UTF-8 encoded)

# the strings have hardcoded max lengths (not the same for all)
# the script will check against there limits and report failure if needed

# usage: place script next to taskforce.exe and execute script
# result is written to taskforce-translated.exe



use strict;
use warnings;

my @tasks;
my $endline     = sprintf("%c",       0x00);
my $newline     = sprintf("%c",       0x0A);
my $skill_start = sprintf("%c%c",     0x81, 0x75);
my $skill_up    = sprintf("%c%c%c%c", 0x81, 0x76, 0x81, 0xAA);
my $skill_down  = sprintf("%c%c%c%c", 0x81, 0x76, 0x81, 0xAB);


sub setupStrings
{
	my $line;
	
	# けんこう
	my $stamina = "stamina";
	
	# きりょく
	my $willpower = "willpower";
	
	# からだ
	my $body = "body";
	
	# こころ
	my $mind = "mind";
	
	# あたま
	my $int = "int";
	
	# おかね
	my $money = "money";

	#バレエで心を磨きます（上級）
	#「こころ」↑「おかね」↓
	$line = "Take ballet lesson (advanced)";
	$line .= $newline . $skill_start . $mind . $skill_up . $skill_start . $money . $skill_down;
	push(@tasks, $line);
	
	#お習字で心を磨きます（上級）
	#「こころ」↑「おかね」↓
	$line = "Refine writing (advanced)";
	$line .= $newline . $skill_start . $mind . $skill_up . $skill_start . $money . $skill_down;
	push(@tasks, $line);
	
	#バレエで心を磨きます
	#「こころ」↑「おかね」↓
	$line = "Take a ballet class";
	$line .= $newline . $skill_start . $mind . $skill_up . $skill_start . $money . $skill_down;
	push(@tasks, $line);
	
	#お習字で心を磨きます
	#「こころ」↑「おかね」↓
	$line = "Practice stylish writing";
	$line .= $newline . $skill_start . $mind . $skill_up . $skill_start . $money . $skill_down;
	push(@tasks, $line);
	
	#バカンス
	#「けんこう」↑「きりょく」↑
	$line = "Holiday";
	$line .= $newline . $skill_start . $stamina . $skill_up . $skill_start . $willpower . $skill_up;
	push(@tasks, $line);
	
	#家でお休みします
	#「けんこう」↑「きりょく」↑
	$line = "Relax at home";
	$line .= $newline . $skill_start . $stamina . $skill_up . $skill_start . $willpower . $skill_up;
	push(@tasks, $line);
	
	#お客様のハードな調教を受けます
	#「おかね」↑「こころ」↓
	$line = "Hard training with a guest";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $mind . $skill_down;
	push(@tasks, $line);
	
	#お客様のお相手をします
	#「おかね」↑「こころ」↓
	$line = "Have sex with a guest";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $mind . $skill_down;
	push(@tasks, $line);
	
	#お客様にご奉仕します
	#「おかね」↑「こころ」↓
	$line = "Perform a sexual favour";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $mind . $skill_down;
	push(@tasks, $line);
	
	#お酒を飲ませて接待します
	#「おかね」↑「こころ」↓
	$line = "Serve drinks and host";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $mind . $skill_down;
	push(@tasks, $line);
	
	#着ぐるみのバイトをします（ハード）
	#「おかね」↑「からだ」↑
	$line = "Work in animal costume (hard)";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $body . $skill_up;
	push(@tasks, $line);
	
	#メイド喫茶で働きます（ハード）
	#「おかね」↑「からだ」↑
	$line = "Work in maid cafe (hard)";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $body . $skill_up;
	push(@tasks, $line);
	
	#着ぐるみのバイトをします
	#「おかね」↑「からだ」↑
	$line = "Work in animal costume";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $body . $skill_up;
	push(@tasks, $line);
	
	#メイド喫茶で働きます
	#「おかね」↑「からだ」↑
	$line = "Work in maid cafe";
	$line .= $newline . $skill_start . $money . $skill_up . $skill_start . $body . $skill_up;
	push(@tasks, $line);
	
	#勉強をします（スパルタ）
	#「あたま」↑「からだ」↓
	$line = "Study (Very Hard)";
	$line .= $newline . $skill_start . $int . $skill_up . $skill_start . $body . $skill_down;
	push(@tasks, $line);
	
	#勉強をします（難しい）
	#「あたま」↑「からだ」↓
	$line = "Study (Hard)";
	$line .= $newline . $skill_start . $int . $skill_up . $skill_start . $body . $skill_down;
	push(@tasks, $line);
	
	#勉強をします（普通）
	#「あたま」↑「からだ」↓
	$line = "Study (Normal)";
	$line .= $newline . $skill_start . $int . $skill_up . $skill_start . $body . $skill_down;
	push(@tasks, $line);
	
	#勉強をします（やさしい）
	#「あたま」↑「からだ」↓
	$line = "Study (Easy)";
	$line .= $newline . $skill_start . $int . $skill_up . $skill_start . $body . $skill_down;
	push(@tasks, $line);
}


my @FILE;

sub loadFile
{
	my $srcfile = "taskforce.exe";

	open INF, $srcfile or die "\nCan't open $srcfile for reading: $!\n";
	
	binmode INF;
	
	my $buffer;
	
	while (
		read (INF, $buffer, 1)
		and push(@FILE, $buffer)
	) {};
	die "Problem copying: $!\n" if $!;
	
	close INF
    or die "Can't close $srcfile: $!\n";
}

sub writeFile
{
	my $destfile = "taskforce-translated.exe";

	open OUTF, ">$destfile" or die "\nCan't open $destfile for writing: $!\n";
	
	binmode OUTF;
	
	foreach(@FILE)
	{
		print OUTF $_;
	}
	
	close OUTF;
}

loadFile;


# address of the first string
my $address = 1197040;

my $active_string = "";

my $EOL_state = 0;
my $string_state = 0;



sub checkEOL
{
	if ($EOL_state == 0)
	{
		if ($FILE[$address] eq $endline)
		{
			$EOL_state = 1;
		}
		elsif ($string_state == 1)
		{
			$FILE[$address] = $endline;
		}
	}
	else
	{
		if ($FILE[$address] ne $endline)
		{
			if ($string_state == 0)
			{
				die "too long string: " . $active_string . "\n";
			}
			$string_state++;
			$EOL_state = 0;
		}
	}
}

sub gotoNextString
{
	while ($string_state < 4)
	{
		$address++;
		checkEOL;
	}
	$string_state = 0;
}


sub writeString
{
	my ($string) = @_;
	
	$active_string = $string;

	while (length $string > 0)
	{
		checkEOL;
		my $char = substr($string, 0, 1);
		$string = substr($string, 1);
		$FILE[$address] = $char;
		$address++;
	}

	checkEOL;
	$FILE[$address] = $endline;
	$string_state = 1;
}

setupStrings;

foreach (@tasks)
{
	writeString($_);
	gotoNextString;
}

writeFile;