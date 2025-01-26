#include <stdio.h>
#include<math.h>

#include <stdio.h>
#include <math.h>

void gradient_descent(double x[], double y[], int n, double learning_rate, int iterations) {
    double a = 0; // Pente initiale
    double b = 0; // Ordonnée initiale
    double n_inv = 1.0 / n; // Évite de recalculer 1/n à chaque itération

    for (int iter = 0; iter < iterations; iter++) {
        double sum_a = 0, sum_b = 0;

        // Calcul des gradients
        for (int i = 0; i < n; i++) {
            double y_pred = a * x[i] + b; // Prédiction actuelle
            double error = y[i] - y_pred; // Erreur

            sum_a += -2 * x[i] * error;  // Gradient par rapport à a
            sum_b += -2 * error;        // Gradient par rapport à b
        }

        // Mise à jour des paramètres
        a -= learning_rate * (n_inv * sum_a);
        b -= learning_rate * (n_inv * sum_b);

        // Optionnel : Afficher les progrès
        if (iter % 100 == 0) {
            printf("Iteration %d: a = %.4f, b = %.4f\n", iter, a, b);
        }
    }

    // Résultat final
    printf("Résultats finaux : a = %.4f, b = %.4f\n", a, b);
}



