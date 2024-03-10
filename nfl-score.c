#include <stdio.h>

//function to calculate the possible combinations of scoring plays
void calculateCombinations(int score) {
    printf("Possible combinations of scoring plays:\n");
    // 6 points for a TD, 3 points for a FG, 2 points for a safety, 1 point for a TD 1-pt, 2 points for a TD 2-pt
    for (int td = 0; td <= score / 6; td++) {
        for (int fg = 0; fg <= score / 3; fg++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                for (int td1pt = 0; td1pt <= score / 7; td1pt++) {
                    for (int td2pt = 0; td2pt <= score / 8; td2pt++) {
                        int totalScore = td * 6 + fg * 3 + safety * 2 + td1pt + td2pt * 2;
                        if (totalScore == score) {
                            printf("%d TD + %d FG + %d Safety + %d TD 1-pt + %d TD 2-pt\n",
                                   td, fg, safety, td1pt, td2pt);
                        }
                    }
                }
            }
        }
    }
}

//main function
int main() {
    int score;
    //prompt user to enter the score
    while (1) {
        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        //call the function to calculate the possible combinations of scoring plays
        calculateCombinations(score);
    }

    return 0;
}
