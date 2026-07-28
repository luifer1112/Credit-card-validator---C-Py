#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;

    do
    {
        //Request card No to user
        card = get_long("Card Number: ");
        //validating general CC range for out of range numbers
        if (card >= 4000000000000 && card < 5600000000000000 )
        {
            //validating VISA 13 digit range numbers
            if (card >= 4000000000000 && card <5000000000000)
            {
                //Geting digit by digit through division module
                int a = card % 10;
                int b = ((card % 100) - a) / 10;
                int c = ((card % 1000) - b) / 100;
                int d = ((card % 10000) - c) / 1000;
                int e = ((card % 100000) - d) / 10000;
                int f = ((card % 1000000) - e) / 100000;
                int g = ((card % 10000000) - f) / 1000000;
                int h = ((card % 100000000) - g) / 10000000;
                int i = ((card % 1000000000) - h) / 100000000;
                int j = ((card % 10000000000) - i) / 1000000000;
                int k = ((card % 100000000000) - j) / 10000000000;
                int l = ((card % 1000000000000) - k) / 100000000000;
                int m = ((card % 10000000000000) - l) / 1000000000000;

                //Verification print. Prints all 13 digits
                printf("Card digits are: a=%i, b=%i, c=%i, d=%i, e=%i, f=%i, g=%i, h=%i, i=%i, j=%i, k=%i, l=%i, m=%i\n", a,b,c,d,e,f,g,h,i,j,k,l,m);

                //Verification print. Prints the double of all 13 digits
                printf("Doubled card digits are: b=%i, d=%i, f=%i, h=%i, j=%i, l=%i\n", b*2,d*2,f*2,h*2,j*2,l*2);


                //Luhn algorithm. digit decomposition of products higher than 9 in to 2 digit numbers
                int b1 = (b * 2) % 10;
                int b2 = (((b * 2) % 100) - b1) / 10;
                int d1 = (d * 2) % 10;
                int d2 = (((d * 2) % 100) - d1) / 10;
                int f1 = (f * 2) % 10;
                int f2 = (((f * 2) % 100) - f1) / 10;
                int h1 = (h * 2) % 10;
                int h2 = (((h * 2) % 100) - h1) / 10;
                int j1 = (j * 2) % 10;
                int j2 = (((j * 2) % 100) - j1) / 10;
                int l1 = (l * 2) % 10;
                int l2 = (((l * 2) % 100) - l1) / 10;

                //Verification print. doubled numbers individual digits
                printf("Doubled number's indiv digits: b1=%i, b2=%i, d1=%i, d2=%i, f1=%i, f2=%i, h1=%i, h2=%i, j1=%i, j2=%i, l1=%i, l2=%i\n", b1,b2,d1,d2,f1,f2,h1,h2,j1,j2,l1,l2);

                //first addition on every other number begining second-to-end
                int sum1 = b1 + b2 + d1 + d2 + f1 + f2 + h1 + h2 + j1 + j2 + l1 + l2;

                //second addition of missing numbers
                int sum2 = sum1 + a + c + e + g + i + k + m;

                //validation of card using module 10
                int tot_rem = sum2 % 10;

                //Addition verification
                printf("sum2= %i\n", sum2);
                printf("total remain= %i\n", tot_rem);

                if (tot_rem == 0)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }

            }
            //Evaluation for AMEX cards (15 digits starting with 34 or 37)
            else if ((card >= 340000000000000 && card < 350000000000000) || (card >= 370000000000000 && card < 380000000000000))
            {
                //Individual extraction of the 15 digits of the card
                int a = card % 10;
                int b = ((card % 100) - a) / 10;
                int c = ((card % 1000) - b) / 100;
                int d = ((card % 10000) - c) / 1000;
                int e = ((card % 100000) - d) / 10000;
                int f = ((card % 1000000) - e) / 100000;
                int g = ((card % 10000000) - f) / 1000000;
                int h = ((card % 100000000) - g) / 10000000;
                int i = ((card % 1000000000) - h) / 100000000;
                int j = ((card % 10000000000) - i) / 1000000000;
                int k = ((card % 100000000000) - j) / 10000000000;
                int l = ((card % 1000000000000) - k) / 100000000000;
                int m = ((card % 10000000000000) - l) / 1000000000000;
                int n = ((card % 100000000000000) - m) / 10000000000000;
                int o = ((card % 1000000000000000) - n) / 100000000000000;

                //Verification print. 15 individual digits
                printf("Card digits are: a=%i, b=%i, c=%i, d=%i, e=%i, f=%i, g=%i, h=%i, i=%i, j=%i, k=%i, l=%i, m=%i, n=%i, o=%i\n", a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);

                //Verification print. Doubled card digits
                printf("Doubled card digits are: b=%i, d=%i, f=%i, h=%i, j=%i, l=%i, n=%i\n", b*2,d*2,f*2,h*2,j*2,l*2,n*2);

                //Breakdown of products into individual digits
                int b1 = (b * 2) % 10;
                int b2 = (((b * 2) % 100) - b1) / 10;
                int d1 = (d * 2) % 10;
                int d2 = (((d * 2) % 100) - d1) / 10;
                int f1 = (f * 2) % 10;
                int f2 = (((f * 2) % 100) - f1) / 10;
                int h1 = (h * 2) % 10;
                int h2 = (((h * 2) % 100) - h1) / 10;
                int j1 = (j * 2) % 10;
                int j2 = (((j * 2) % 100) - j1) / 10;
                int l1 = (l * 2) % 10;
                int l2 = (((l * 2) % 100) - l1) / 10;
                int n1 = (n * 2) % 10;
                int n2 = (((n * 2) % 100) - n1) / 10;

                //Verification print. Doubled numbers for first addition
                printf("Doubled number's indiv digits: b1=%i, b2=%i, d1=%i, d2=%i, f1=%i, f2=%i, h1=%i, h2=%i, j1=%i, j2=%i, l1=%i, l2=%i, n1=%i, n2=%i\n", b1,b2,d1,d2,f1,f2,h1,h2,j1,j2,l1,l2,n1,n2);

                //first addition on every other number begining second-to-end
                int sum1 = b1 + b2 + d1 + d2 + f1 + f2 + h1 + h2 + j1 + j2 + l1 + l2 + n1 + n2;

                //second addition of missing digits
                int sum2 = sum1 + a + c + e + g + i + k + m +o;

                //card verification with module 10
                int tot_rem = sum2 % 10;

                //addition verification
                printf("sum2= %i\n", sum2);
                printf("total remain= %i\n", tot_rem);

                if (tot_rem == 0)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            //Evaluation for 16-digit VISA and MASTERCARD
            else if ((card >= 4000000000000000 && card < 5000000000000000) || (card >= 5100000000000000 && card < 5600000000000000))
            {
                //asess 16 digits VISA and MC
                int a = card % 10;
                int b = ((card % 100) - a) / 10;
                int c = ((card % 1000) - b) / 100;
                int d = ((card % 10000) - c) / 1000;
                int e = ((card % 100000) - d) / 10000;
                int f = ((card % 1000000) - e) / 100000;
                int g = ((card % 10000000) - f) / 1000000;
                int h = ((card % 100000000) - g) / 10000000;
                int i = ((card % 1000000000) - h) / 100000000;
                int j = ((card % 10000000000) - i) / 1000000000;
                int k = ((card % 100000000000) - j) / 10000000000;
                int l = ((card % 1000000000000) - k) / 100000000000;
                int m = ((card % 10000000000000) - l) / 1000000000000;
                int n = ((card % 100000000000000) - m) / 10000000000000;
                int o = ((card % 1000000000000000) - n) / 100000000000000;
                int p = ((card % 10000000000000000) - o) / 1000000000000000;


                //16 Digit verification
                printf("Card digits are: a=%i, b=%i, c=%i, d=%i, e=%i, f=%i, g=%i, h=%i, i=%i, j=%i, k=%i, l=%i, m=%i, n=%i, o=%i, p=%i\n", a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);

                //first doubled digit verification
                printf("Doubled card digits are: b=%i, d=%i, f=%i, h=%i, j=%i, l=%i, n=%i, p=%i\n", b*2,d*2,f*2,h*2,j*2,l*2,n*2,p*2);

                //Extract individual digits
                int b1 = (b * 2) % 10;
                int b2 = (((b * 2) % 100) - b1) / 10;
                int d1 = (d * 2) % 10;
                int d2 = (((d * 2) % 100) - d1) / 10;
                int f1 = (f * 2) % 10;
                int f2 = (((f * 2) % 100) - f1) / 10;
                int h1 = (h * 2) % 10;
                int h2 = (((h * 2) % 100) - h1) / 10;
                int j1 = (j * 2) % 10;
                int j2 = (((j * 2) % 100) - j1) / 10;
                int l1 = (l * 2) % 10;
                int l2 = (((l * 2) % 100) - l1) / 10;
                int n1 = (n * 2) % 10;
                int n2 = (((n * 2) % 100) - n1) / 10;
                int p1 = (p * 2) % 10;
                int p2 = (((p * 2) % 100) - p1) / 10;

                //Verification print first addition
                printf("Doubled number's indiv digits: b1=%i, b2=%i, d1=%i, d2=%i, f1=%i, f2=%i, h1=%i, h2=%i, j1=%i, j2=%i, l1=%i, l2=%i, n1=%i, n2=%i, p1=%i, p2=%i\n", b1,b2,d1,d2,f1,f2,h1,h2,j1,j2,l1,l2,n1,n2,p1,p2);

                //first addition of doubles begining second to first
                int sum1 = b1 + b2 + d1 + d2 + f1 + f2 + h1 + h2 + j1 + j2 + l1 + l2 + n1 + n2 + p1 + p2;

                //second addition on missing digits
                int sum2 = sum1 + a + c + e + g + i + k + m +o;

                //card verification
                int tot_rem = sum2 % 10;

                printf("sum2= %i\n", sum2);
                printf("total remain= %i\n", tot_rem);

                //Brand differentiation by initial digit ('p') if the sum is a multiple of 10
                if (tot_rem == 0 && p == 4)
                {
                    printf("VISA\n");
                }
                else if (tot_rem == 0 && p == 5)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }while (card < 4000000000000 || card >= 5600000000000000);


}


