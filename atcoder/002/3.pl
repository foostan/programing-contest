use strict;
use warnings;

chomp( my $n = <STDIN>);
chomp( my $c = <STDIN>);
my @b = ('A','B','X','Y');
my $minl=$n;

foreach my $l1(@b){
	foreach my $l2(@b){
		foreach my $r1(@b){
			foreach my $r2(@b){
				my $tmp = $c;
				$tmp =~ s/$l1$l2/L/g;
				$tmp =~ s/$r1$r2/R/g;
				my $l = length($tmp);
				$minl = $minl>$l?$l:$minl;
			}
		}
	}
}

print "$minl\n";

