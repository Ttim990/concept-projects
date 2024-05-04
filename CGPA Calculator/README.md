#TITLE:         CGPA CALCULATOR
#DESCRIPTION:   THIS C++ PROGRAM CAN PERFORMS TWO FUNCTIONS, YOU CAN ENTER ANY NUMBER OF SUBJECT SCORES
                EACH WITH THE CORRESPONDING CREDIT UNITS(CUs), AND THE PROGRAM WILL CALCULATE THE CGPA.
                SECONDLY YOU CAN ENTER A CURRENT CGPA, PLUS THE TOTAL NUMBER OF CREDIT UNITS FOR THAT CGPA,
                AND YOU CAN THEN ENTER ANY MORE SUBJECTS AND (CUs) TO GET THE CUMMULATIVE AVERAGE.

                THE MAXIMUM GRADE POINT USED IS 5.0

                THE GRADING POINT ALLOCATION: { (80-100): 5.0, (75-79.9):4.5, (70-74.9): 4.0, (65-69.9): 3.5,
                                                (60-64.9): 3.0, (55-59.9): 2.5, (50-54.5): 2.0,  (45-49.9): 1.5, 
                                                (40-44.9): 1.0, (35-39.9): 0.5, (0-34.9): 0.0}


#Features:   The program is built using functions;

            getGradePoint( mark or score): Returns the grade point corresponding to a given mark or score entered as an argument
            getCGPA(args) : This function has two overloads.
                            The first overload takes in two vectors, one for the marks and the other 
                            for the corresponding credit Units (CUs) and returns the calculated CGPA. this overload is used in the case when the CGPA is determined from the beginning i.e. no current CGPA.
                            The second overload takes in two more arguments, the current CGPA and the total number of Cedit Units used to determine the current CGPA. these on addition to the two vectors from the previous overload.

            CGPA_Calculator():  This function performs all the necessary logic and prompting required for the program
                            to run.


#Usage:  The program prompts for user input at various stages of the program in the console window where the data is 
        entered, separated by spaces.


#Contributions:  Contributions to this code are welcome. follow the procedures on github to contibute to this code.

#License: This project is licensed under the MIT License -see the [LICENSE](LICENSE)

