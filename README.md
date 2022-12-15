# CS415-programming-language-Compiler

CS415 programming language Description:
o	Language is case-insensitive
o	All Keywords are reserved (Shown in upper case for emphasis)
o	Parenthesis re not used in a CALL statement if no parameters are being passed.
o	JASON has 4 arithmetic operators (+,-,* and /) and 4 relational operators (=,>,<,!). The (!) is used to denote “is not equal to”
o	The entire operator set consists of one-character operators
o	Comments are enclosed in braces {}

CS415 has valid types of statements:
•	READ Identifier
•	WRITE Identifier
•	Begin Statement
•	End statement
•	Declare statement
•	Data type identifier
•	SET Identifier = Expression
•	IF Condition THEN Statement(s) ELSE Statement(s) ENDIF
•	WHILE Condition DO Statement(s) ENDWHILE
•	UNTIL Condition DO Statement(s) ENDUNTIL
•	CALL Identifier(ArgList)

*Example scanner input and output*
Input code:
Integer x;
Set x = 1;

Output Tokens:
Datatype
Id
Semicolon
Set 
Id
Equal
Num_constant
Semicolon
