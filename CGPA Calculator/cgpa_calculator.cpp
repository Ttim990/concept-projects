/*
*TITLE:         CGPA CALCULATOR AND UPDATER...

*DESCRIPTION:   THE PROGRAM PERFORMS TWO FUNCTIONS, YOU CAN ENTER ANY NUMBER OF SUBJECT SCORES
                EACH WITH THE CORRESPONDING CREDIT UNITS(CUs), AND THE PROGRAM WILL CALCULATE THE CGPA.
                SECONDLY YOU CAN ENTER A CURRENT CGPA, PLUS THE TOTAL NUMBER OF CREDIT UNITS FOR THAT CGPA,
                AND YOU CAN THEN ENTER ANY MORE SUBJECTS AND (CUs) TO GET THE CUMMULATIVE AVERAGE.

                THE MAXIMUM GRADE POINT USED IS 5.0

                THE GRADING POINT ALLOCATION: { (80-100): 5.0, (75-79.9):4.5, (70-74.9): 4.0, (65-69.9): 3.5,
                                                (60-64.9): 3.0, (55-59.9): 2.5, (50-54.5): 2.0,  (45-49.9): 1.5, 
                                                (40-44.9): 1.0, (35-39.9): 0.5, (0-34.9): 0.0}
*
*/

#include <vector>
#include <iostream>
#include <iomanip>

//A function to obtain the grade point of any mark
float getGradePoint(float mark){
    float start = 80, GP = 5.0;

    while(mark < start){        // Using a loop to find the Grade point(GP) based on the 
        GP-=0.5;                // pattern that the GP drops every 5.0 drop in the mark
        start -= 5.0;
    };
    return GP;
}

//getting the CGPA given Marks and Weights(CUs) only
float getCGPA(std::vector<float> marks, std::vector<int> CUs){
    float weighted_sum = 0;
    int CU_sum = 0;
    size_t size = marks.size();

    for(int i = 0; i < size; ++i){
        weighted_sum += getGradePoint(marks[i]) * CUs[i];
    }
    for(int cu : CUs){
        CU_sum += cu;
    }

    return weighted_sum/CU_sum;
}

// Now Given the current CGPA and the current CU_total (Credit Unit Sum) on addition to the new data
float getCGPA(float current_CGPA, int CU_total, std::vector<float> marks, std::vector<int> CUs){
    float weighted_sum = current_CGPA * CU_total;
    float GP = 0;
    int CU_sum = CU_total;
    size_t size = marks.size();

    for(int i = 0; i < size; ++i){
        weighted_sum += getGradePoint(marks[i]) * CUs[i];
    }
    for(int cu : CUs){
        CU_sum += cu;
    }

    return weighted_sum/ CU_sum;
}

//The function that calculates the CGPA taking a few condintions
float CGPA_Calculator(){
    int option;
    std::cout << "CGPA Caclulator: Select an option (1 / 2):"<< std::endl;
    std::cout << "1. From current CGPA\n2. No current CGPA\nEnter -1 to quit" << std::endl;
    std::cout << "Option: " << std::endl;
    std::cin >> option;
        
    std::vector<float> marks;
    std::vector<int> CUs;
    float current_CGPA=0, mark, CGPA;
    int CU;
    int CU_total;

    switch (option){
        case 1:
            std::cout << "Enter current CGPA: ";
            std::cin >> current_CGPA;
            std::cout << "Enter CU_total: ";
            std::cin >> CU_total;
            std::cout << "Enter mark and CU separated by a space: (enter -1 to finish)" << std::endl;
        
            while(true){
                std::cin >> mark;
                if(mark == -1) break;
                std::cin >> CU;
                if( CU == -1 ) break;
                
                marks.push_back(mark);
                CUs.push_back(CU);
            }
            CGPA = getCGPA(current_CGPA, CU_total, marks, CUs);

        case 2:
            std::cout << "Enter mark and CU separated by a space: (enter -1 to finish)" << std::endl;
            while(true){
                std::cin >> mark;
                if(mark == -1) break;
                std::cin >> CU;
                if( CU == -1 ) break;
                marks.push_back(mark);
                CUs.push_back(CU);
            }
            CGPA = getCGPA(marks, CUs);
            break;

        case -1:
            return 0;

        default:
            std::cout << "unrecognized input!" <<std::endl;
            break;
        }

    return CGPA;
}

int main(){
    std::cout << "CGPA: " << std::setprecision(3) << CGPA_Calculator() << std::endl;
    return 0;
}
