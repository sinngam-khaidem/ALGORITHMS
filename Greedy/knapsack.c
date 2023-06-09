# include<stdio.h>


//n = no. of objects.
//x[i] = fraction of the i th object selected.

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], total_profit = 0; 
   int i, j, M;
   M = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > M)
         break;
      else {
         x[i] = 1.0;
         total_profit = total_profit + profit[i];
         M = M - weight[i];
      }
   }

   if (i < n)
      x[i] = M / weight[i];

   total_profit = total_profit + (x[i] * profit[i]);

   printf("Fraction of object considered:- ");
   for (i = 0; i < n; i++)
      printf("%.2f\t", x[i]);

   printf("Maximum profit is:- %.2f\n", total_profit);

}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("Enter the no. of objects:- ");
   scanf("%d", &num);

   printf("Enter the wts and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("Enter the capacity of knapsack:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(num, weight, profit, capacity);
   return(0);
}

