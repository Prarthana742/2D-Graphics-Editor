 
  /* 2D Graphics Editor

   This program uses a 2D character array as a drawing canvas.
   Users can draw different shapes such as rectangles,
   lines, triangles and circles using '*' characters. */


#include<stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 50

/* Canvas used to store the drawing */

char canvas[ROWS][COLS];

/* Function Prototypes */
void initializeCanvas();
printf("Welcome to the Mini Graphics Drawing System!\n");
printf("Canvas Size: %d Rows x %d Columns\n", ROWS, COLS);
void displayCanvas();

void drawRectangle(int x, int y, int width, int height);
void drawLine(int x1, int y1, int x2, int y2);
void drawTriangle(int x, int y, int height);
void drawCircle(int centerX, int centerY, int radius);

void clearCanvas();
void deleteArea(int x, int y, int width, int height);
void modifyArea();

   /* Main function:
   Displays menu and handles user choices. */

int main()
{
    int choice;
    int x, y, width, height;
    int x1, y1, x2, y2;
    int radius;
    int totalShapes=0;

    initializeCanvas();

  /* Repeatedly display menu until user exits */

    do
    {
        printf("\n===== Mini Graphics Drawing System =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Clear Canvas\n");
        printf("6. Display Canvas\n");
        printf("7. Delete area\n");
        printf("8. Modify Area\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &width, &height);
                drawRectangle(x, y, width, height);
                printf("Rectangle added successfully!\n");
                break;

            case 2:
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                drawLine(x1, y1, x2, y2);
                printf("Line added successfully!\n");
                break;

            case 3:
                printf("Enter x y height: ");
                scanf("%d%d%d", &x, &y, &height);
                drawTriangle(x, y, height);
                printf("Triangle added successfully!\n");
                break;

            case 4:
                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d", &x, &y, &radius);
                drawCircle(x, y, radius);
                printf("Circle added successfully!\n");
                break;

            case 5:
                clearCanvas();
                printf("Canvas cleared.\n");
                break;

            case 6:
                displayCanvas();
                break;

            case 7:
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x, &y, &width, &height);

                deleteArea(x, y, width, height);
                printf("Selected area deleted successfully!\n");
                break;

            case 8:
                modifyArea();
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 8);

    return 0;
}


 
   /* Fill the entire canvas with '_'
   to represent an empty drawing area. */


void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
       /* Traverse each column of the current row */
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void clearCanvas()
{
    initializeCanvas();
}


   /* Display the complete drawing
   stored inside the canvas. */

void displayCanvas()
{
    int i, j;

    printf("\n");
    /* Visit every row */

    for(i = 0; i < ROWS; i++)
    {
      /* Print all characters in the row */
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }

        printf("\n");
    }
}


   /* Draw a rectangle using '*'
   starting from the given x and y position. */

void drawRectangle(int x, int y, int width, int height)
{
   int i,j;

/* Move through each row of the rectangle */

for(i = y; i < y + height && i < ROWS; i++)
{
    /* Move through each column of the rectangle */

    for(j = x; j < x + width && j < COLS; j++)
    {
        canvas[i][j] = '*';
    }
}
}



/* Draw horizontal,vertical and diagonal lines */
void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2) /* Horizontal */
    {
        for(i = x1; i <= x2 && i < COLS; i++)
        {
            canvas[y1][i] = '*';
        }
    }
    else if(x1 == x2) /* Vertical */
    {
        for(i = y1; i <= y2 && i < ROWS; i++)
        {
            canvas[i][x1] = '*';
        }
    }
    else /* Simple diagonal */
    {
        int x = x1;
        int y = y1;

        while(x <= x2 && y <= y2 &&
              x < COLS && y < ROWS)
        {
            canvas[y][x] = '*';
            x++;
            y++;
        }
    }
}

/* Draw triangle by increasing row by row */
void drawTriangle(int x, int y, int height)
{
    int i, j;
   /* Create each row of the triangle */

    for(i = 0; i < height; i++)
    {
     /* Add stars on both sides of the center */
        for(j = -i; j <= i; j++)
        {
            if(y + i < ROWS &&
               x + j >= 0 &&
               x + j < COLS)
            {
                canvas[y + i][x + j] = '*';
            }
        }
    }
}

/* Draw circle using distance from the centre point */
void drawCircle(int centerX, int centerY, int radius)
{
    int x, y;
   /* Check every position on the canvas */

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
          /* Calculate distance from center */

            int dx = x - centerX;
            int dy = y - centerY;

          /* Mark points belonging to the circle */

            int value = dx * dx + dy * dy;

            if(value >= radius * radius - radius &&
               value <= radius * radius + radius)
            {
                canvas[y][x] = '*';
            }
        }
    }
}
/* Delete a selected area from the canvas */
void deleteArea(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}
