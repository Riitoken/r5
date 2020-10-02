README.TXT

THE R5 PARSER

The C programming language provides the single best ASCII string splitter in the history of ASCII string splitters.

     sscanf(line,"%s %s[^\r^\n]s",lval,rval);

This line of C source code, that has been supported by C since the beginning, will split a line of text into a left value and a right value. For data organized as (KEY,VALUE) pairs, this parser is all you need to parse a KEY and a VALUE from a single line of text - provided that your KEYs contain no white-space, because white-space is the default delimiter for the C RTL scan functions.

With this parser and C++ containers, you can model any real data that can exist in digital form.

     R5 NULL HYPOTHESIS: "All digital data that actually exists, can be modeled in 5th normal form (i.e. key/value pairs)."

To falsify this, you must identify and/or describe data that can exist in digital form that cannot be modeled in 5th normal form. This includes anything currently modeled as XML or JSON or CSV or any of their cousins.

The R5 parser is faster than any of the aforementioned formats and you do not need any special punctuation formatting other than white-space and CRLF. This means that R5 text files are very user friendly in the context of reading and editing.

The default official extenstion for an R5 text file is ".r5.txt" , this identifies the natural encoding as human readable text, and it identifies the base structure as R5.

Example:

class     dagger
name      Sting
owner     Bilbo
make      Elvish
forge     Gondolin
bequeath  Frodo
special   orc-alarm
glow      blue
length    23in
weight    2lbs
age       ancient
endclass

