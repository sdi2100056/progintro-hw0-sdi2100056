#include <stdio.h>
#include <stdlib.h>

/*Συνάρτηση για υπολογισμό αθροίσματοσ των γνήσιων διαιρετών*/
long long get_divisor_sum(long long number) {
    if (number<=1) return 0;
    long long total =1;
    for (long long i=2; i*i<=number; i++){
        if (number% i == 0){
            total=total +i;
            if (i!= number /i){ /*Αν δεν είναι τέλειο τετράγωνο προσέθεσε το αντίστοιχο πηλίκο*/
                total=total +number/i;
            }
        }
    }
    return total;
}

int main (){
    long long startNumber ;
    long long maxLength ;
    char choice ;

    /*Είσοδος χρήστη*/
    printf ("Give the starting number:");
    if(scanf ("%lld", & startNumber) !=1 || startNumber <1){
        fprintf (stderr, "Invalid number.\n");
        return 1;
    }
    printf("Give the maximum length:");
    if (scanf ("%lld", &maxLength) !=1 || maxLength <0){
        fprintf (stderr, "Invalid length.\n");
        return 1;
    }
    printf ("Do you want to print the full sequence ('f') or just the length ('l')? ");
    if (scanf (" %c", &choice) !=1 || (choice !='f' && choice != 'l')){
        fprintf (stderr, "Invalid choice.\n");
        return 1;
    }

    /*Αρχικοποίηση μεταβλητών*/

    long long currentNumber = startNumber;
    long long steps =0;
    const long long LIMIT =10000000000000000;

    /*Αν θέλει να δεί ο χρήστησ την πλήρη μορφή*/
    if (choice =='f'){
        printf ("%lld\n",currentNumber);
    }

    /*Υπολογισμόσ τησ υπακολουθίας*/
    while (currentNumber >0 && currentNumber <=LIMIT)
    {
        if (maxLength >0 && steps >=maxLength){
            break;
        }
    long long nextValue = get_divisor_sum (currentNumber);
    steps++;

    /*Αν είναι τέλειος ο αριθμός (κύκλος) τότε σταματάει*/
    if (nextValue ==currentNumber){
        break;
    }
    currentNumber = nextValue;
    if (choice =='f'){
        printf ("%lld\n", currentNumber);
    }
    /*Έλεγχος για το όριο */
    if (currentNumber >LIMIT){
    fprintf (stderr,"Number exceeded the limit (%lld).Stopping.\n",LIMIT);
    return 1;
    }
    }
    if (choice =='l'){
        printf ("Length is : %lld\n", steps);
    }
    printf ("Press enter to exit");
    getchar();
    return 0;
}
