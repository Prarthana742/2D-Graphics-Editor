#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

/* Function Prototypes */
void initializeCanvas();
void displayCanvas();

void drawRectangle(int x, int y, int width, int height);
void drawLine(int x1, int y1, int x2, int y2);
void drawTriangle(int x, int y, int height);
void drawCircle(int centerX, int centerY, int radius);

void clearCanvas();

int main()
{
    int choice;
    int x, y, width, height;
    int x1, y1, x2, y2;
    int radius;

    initializeCanvas();

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Clear Canvas\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &width, &height);
                drawRectangle(x, y, width, height);
                break;

            case 2:
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                drawLine(x1, y1, x2, y2);
                break;

            case 3:
                printf("Enter x y height: ");
                scanf("%d%d%d", &x, &y, &height);
                drawTriangle(x, y, height);
                break;

            case 4:
                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d", &x, &y, &radius);
                drawCircle(x, y, radius);
                break;

            case 5:
                clearCanvas();
                printf("Canvas cleared.\n");
                break;

            case 6:
                displayCanvas();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}

/* Initialize canvas with '_' */
void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
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

/* Display canvas */
void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }

        printf("\n");
    }
}

/* Draw Rectangle */
void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

/* Draw Horizontal / Vertical / Diagonal Line */
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

/* Draw Triangle */
void drawTriangle(int x, int y, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
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

/* Draw Simple Circle */
void drawCircle(int centerX, int centerY, int radius)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int dx = x - centerX;
            int dy = y - centerY;

            int value = dx * dx + dy * dy;

            if(value >= radius * radius - radius &&
               value <= radius * radius + radius)
            {
                canvas[y][x] = '*';
            }
        }
    }
}