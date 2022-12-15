# CS415-programming-language-Compiler

### CS415 programming language Description:</br>
<li> Language is case-insensitive </li>
<li> All Keywords are reserved (Shown in upper case for emphasis) </li>
<li> Parenthesis re not used in a CALL statement if no parameters are being passed. </li>
<li> JASON has 4 arithmetic operators (+,-,* and /) and 4 relational operators (=,>,<,!). The (!) is used to denote “is not equal to” </li>
<li> The entire operator set consists of one-character operators </li>
<li> Comments are enclosed in braces {} </li>

### CS415 has valid types of statements:</br>
<li> READ Identifier
<li> WRITE Identifier
<li> Begin Statement
<li> End statement
<li> Declare statement
<li> Data type identifier
<li> SET Identifier = Expression
<li> IF Condition THEN Statement(s) ELSE Statement(s) ENDIF
<li> WHILE Condition DO Statement(s) ENDWHILE
<li> UNTIL Condition DO Statement(s) ENDUNTIL
<li> CALL Identifier(ArgList)

### Example scanner input and output: </br>
<li> Input code:</br>
Integer x;</br>
Set x = 1;</br>
</br>
<li> Output Tokens:</br>
Datatype</br>
Id</br>
Semicolon</br>
Set </br>
Id</br>
Equal</br>
Num_constant</br>
Semicolon</br>
