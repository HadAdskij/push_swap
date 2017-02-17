# push_swap
project for UNIT Factory, main aim to sort stack of integer numbers with the smallest set of given commands. For details read pdf file.

After command make will be created 3 program:
 - push_swap;
 - checker;
 - nbr_generator.
 
 push_swap - program that take array of integer numbers given as arguments and display list of commands to sort this numbers.<br>
 checker - just check if commands from push_swap (checker reads commans from standart output) sort given array of numbers.<br>
 nbr_generator - generate random integer numbers.<br>
 
  
  Flags for push_swap:<br>
 -d - show list of errors;
 -ss - disable bruteforce option.
 
 Flags for checker:<br>
 -d - show list of errors;
 -v - visualization;
 -c - color visualization;
 -n - show number of steps.

  Examples of usage:<br>
  
 ./nbr_generator 20<br>
 6836736 444383891 836897380 1328607045 1713366518 624362687 1161761101 1722832850 717240212 153630648 1464854022 462244680 1060448729 921455017 1720715331 416665911 1942952166 2430765 774386158 99295529 <br>
 
 ARG="`./nbr_generator 500`"; ./push_swap -ss $ARG | ./checker -n $ARG<br>
  OK
  Commands number: 5086

