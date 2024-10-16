```
Menu:
1. Play
2. Quit
Select an option:1
 Enter the name for Army 1:a
 Enter the size for Army 1 (up to 10):b
 Enter the name for Army 2: Enter the
size for Army 2 (up to 10): Battle begins between a and !
Attacker            Damage    Army      Defender            Defender's Health   Army

a total health: 0
 total health: 0
It's a tie!

Menu:
1. Play
2. Quit
Select an option: Quitting the game.
```


**NG 10/15/2024**
* to avoid redundancy, call setCreature inside all other individual setter functions, including c’tor(s) and d’tor; this way validation and set statements are not all over the class code
* inline functions do not adhere to the best practices -5
* If a user enters a value of a wrong data type, the program goes into an infinite loop or  crashes or terminates or prints the menu multiple times ( in menu add cin.clear(); cin.ignore(...);  in  the default case of the switch) ; validate user input -5
* inadequate and/ insufficient test data/ not all possible cases have been tested: e.g. each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is  a valid  record ; all menu options should be tested; what is the point for the exact values several times? -5
* const; if it is not 1 or 0 make it const; in case of ASCII values use chars, e.g temp>’a’  what’s 100?-5
* allows user to have armies of different size, see assignment -5
* modularization: each menu option should have it is own function with the possible exception of quit statement -2
* do not use “this” unless you are really have to, adds clutter reduces readability but no meaningful info;  newHealth-2
* readability, comments;  do not state obvious, remove outdated code; comments supposed to help and not create unnecessary clutter; "Code never lies, comments sometimes do." - Ron Jeffries” ; what is the purpose of the comments as this(ese) one(s);  -1
```
// Creature class
class Creature {
```
* allows implicit conversions -2
*  default health and strength -2
* uses <array> -20
* waste of time – call to max function ; health= health – (damage>health? 0: damage); -1
* excessive use of printf/cout/cin/ file stream/stringstream and/or endl and/or << >>; applies to all output not just menu-5
//e.g.
```
cout << "\n\nMenu:\n”

“1. Encrypt\n”

“2. Decrypt\n”

“3. Quit\n"<<endl;
```
* << not needed between strings
* Do not use endl where “\n” can be used, you can always append/prepend it to the previous and/or next string to be outputted
* put ‘\n’ is at the end of the previous whenever possible  
* Should print a couple of blank lines before the menu to separate from the lines of text above it
* no need for the “.” at the end of menu options; it is just clutter but no useful info to a user* no need for the “.” at the end of menu options; it is just a clutter but no useful info to a user
 	* input>>name>>id>gpal;

