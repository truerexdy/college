#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term {
    int coeff;
    int x_exp;
    int y_exp;
    int z_exp;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* header;
} Polynomial;

Term* createTerm(int coeff, int x_exp, int y_exp, int z_exp) {
    Term *newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->x_exp = x_exp;
    newTerm->y_exp = y_exp;
    newTerm->z_exp = z_exp;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(Polynomial *poly, int coeff, int x_exp, int y_exp, int z_exp) {
    Term *newTerm = createTerm(coeff, x_exp, y_exp, z_exp);
    if (poly->header == NULL) {
        poly->header = newTerm;
        poly->header->next = poly->header;
    } else {
        Term *temp = poly->header;
        while (temp->next != poly->header) {
            temp = temp->next;
        }
        temp->next = newTerm;
        newTerm->next = poly->header;
    }
}

int evaluatePolynomial(Polynomial *poly, int x, int y, int z) {
    int result = 0;
    Term *temp = poly->header;
    if (temp != NULL) {
        do {
            result += temp->coeff * pow(x, temp->x_exp) * pow(y, temp->y_exp) * pow(z, temp->z_exp);
            temp = temp->next;
        } while (temp != poly->header);
    }
    return result;
}

Polynomial* addPolynomials(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *polySum = (Polynomial*)malloc(sizeof(Polynomial));
    polySum->header = NULL;

    Term *temp1 = poly1->header;
    Term *temp2 = poly2->header;

    if (temp1 != NULL && temp2 != NULL) {
        do {
            insertTerm(polySum, temp1->coeff, temp1->x_exp, temp1->y_exp, temp1->z_exp);
            temp1 = temp1->next;
        } while (temp1 != poly1->header);

        do {
            Term *tempSum = polySum->header;
            int found = 0;
            do {
                if (tempSum->x_exp == temp2->x_exp && tempSum->y_exp == temp2->y_exp && tempSum->z_exp == temp2->z_exp) {
                    tempSum->coeff += temp2->coeff;
                    found = 1;
                    break;
                }
                tempSum = tempSum->next;
            } while (tempSum != polySum->header);

            if (!found) {
                insertTerm(polySum, temp2->coeff, temp2->x_exp, temp2->y_exp, temp2->z_exp);
            }
            temp2 = temp2->next;
        } while (temp2 != poly2->header);
    }

    return polySum;
}

void printPolynomial(Polynomial *poly) {
    Term *temp = poly->header;
    if (temp != NULL) {
        do {
            printf("%d*x^%d*y^%d*z^%d ", temp->coeff, temp->x_exp, temp->y_exp, temp->z_exp);
            temp = temp->next;
            if (temp != poly->header) {
                printf("+ ");
            }
        } while (temp != poly->header);
    }
    printf("\n");
}

int main() {
    Polynomial *poly1 = (Polynomial*)malloc(sizeof(Polynomial));
    poly1->header = NULL;
    Polynomial *poly2 = (Polynomial*)malloc(sizeof(Polynomial));
    poly2->header = NULL;

    insertTerm(poly1, 6, 2, 2, 1);
    insertTerm(poly1, -4, 0, 1, 5);
    insertTerm(poly1, 3, 3, 1, 1);
    insertTerm(poly1, 2, 1, 5, 1);
    insertTerm(poly1, -2, 1, 1, 3);

    insertTerm(poly2, 1, 1, 1, 1);
    insertTerm(poly2, 2, 2, 2, 2);

    printf("POLY1: ");
    printPolynomial(poly1);
    printf("POLY2: ");
    printPolynomial(poly2);

    printf("Enter the value of x, y and z:\n");
    int x, y, z = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    int result = evaluatePolynomial(poly1, x, y, z);
    printf("Evaluated POLY1 at x=%d, y=%d, z=%d: %d\n", x, y, z, result);

    Polynomial *polySum = addPolynomials(poly1, poly2);
    printf("POLYSUM: ");
    printPolynomial(polySum);

    free(poly1);
    free(poly2);
    free(polySum);

    return 0;
}
