# Sig: signature functions

use strict;
use warnings;
use 5.010;
use Data::Dumper;
use Function::Parameters;


#
# my $word = dst2word( $type );
#	Taking a Duncan Simple Type ($type), essentially a typename followed
#	by zero or more '*'s, produce a single word description, eg. if type
#	is "char **", the word is "charstarstar".
#
fun dst2word( $type )
{
	$type =~ s/\*/star/g;
	$type =~ s/\s+//g;
	return $type;
}


#
# my $sigstr = makesig( $returntype, @params );
#	Build a signature string, eg. if $returntype is "char *", and @params
#	are ( "void *x", "int y", "char **z" ), the signature string is
#	"charstar_voidstar_int_charstarstar".
#       ^returntype        ^second param
#	          ^first param ^third param
#
fun makesig( $returntype, @params )
{
	$returntype = dst2word( $returntype );
	@params      = ("void x") if @params == 0;
	my $argtypes = join( '_',
		map {
			s/\w+$//;		# remove the parameter name
			dst2word( $_ )
		} @params );
	return "${returntype}_${argtypes}";
}


1;
