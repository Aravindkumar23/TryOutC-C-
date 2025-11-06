Number should be divisble by 1 or itself 

int num,i,flag=0;
num = 7;
for (i = 2; i<=num /2; i++) { 3.5 = 3
    if (num % i == 0) {
        flag = 1;
        break;
    }
}

/* Example nested for loop: 5x5 multiplication table */
for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
        printf("%d ", row * col);
    }
    printf("\n");
}

/* Example: break exits the innermost loop immediately */
for (int j = 1; j <= 10; ++j) {
    if (j == 5) {
        /* stop the loop when j reaches 5; values 5..10 are not printed */
        break;
    }
    printf("%d ", j); // will not be touched 
}
printf("\n");

/* Example: break in a switch prevents fall-through to the next case */
int x = 2;
switch (x) {
    case 1:
        printf("one\n");
        break; /* without this, execution would continue into case 2 */
    case 2:
        printf("two\n");
        break;
    default:
        printf("other\n");
}

/* Example: use break to stop a search when item is found */
int target = 7;
for (int k = 0; k < 20; ++k) {
    if (k == target) {
        printf("found %d at index %d\n", target, k);
        break; /* exit loop as soon as target is found */
    }
}

/* Example: break in nested loops only exits the inner loop */
for (int r = 1; r <= 3; ++r) {
    for (int c = 1; c <= 3; ++c) {
        if (c == 2) {
            /* breaks out of the inner 'c' loop only; outer 'r' loop continues */
            break;
        }
        printf("(%d,%d) ", r, c);
    }
    printf("\n");
}

if (flag == 0)  printf("prime number" );
else printf("not prime number");
i<=3
i= 3

4 % 2 == 0
    => flag = 1
    => not prime number


7 % 2 = 1
7 % 3 = 1
  

3.5 = 3
2/2 = 1 

3/2 = 1.9 int 1 

2.9 int 2 

float  double

% modulus operator gives remainder 

2/2 = 1 remainder 0

3/2 = 1 remainder 1

2.9 int 2

float  double

164 bit signed integer range is from
-32,767 to +32,767
64 bit signed integer range is from
-2,147,483,648 to +2,147,483,647.