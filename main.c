#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE_TABLE 30
#define CHAR_SYMBOL 65
#define SPACE_SYMBOL 32
#define SHOOT_SYMBOL 33
#define ENEMY_SYMBOL 87

char table[SIZE_TABLE][SIZE_TABLE]={
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,65,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
};
char temp_table[SIZE_TABLE][SIZE_TABLE];

int enemy_count = 0;
int char_coord = 14;

void print_table(){
    int change = 0;
    int count=0;

    for (int i = 0; i < SIZE_TABLE; i++){
        for (int j = 0; j < SIZE_TABLE; j++){
            if(temp_table[i][j] != table[i][j]){
                change = 1;
            }
            if (table[i][j]==ENEMY_SYMBOL){
                count++;
            }
        }
    }
    enemy_count=count;

    if (change == 1){
        printf("Enemys alive: %d",enemy_count);
        system("cls"); 
        for (int i = 0; i < SIZE_TABLE; i++){
            for (int j = 0; j < SIZE_TABLE; j++){
                printf("%c", table[i][j]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < SIZE_TABLE; i++){
        for (int j = 0; j < SIZE_TABLE; j++){
            temp_table[i][j]=table[i][j];
        }
    }
}

void move_char(char dir){
    if (dir=='d'){
        char_coord++;
        if (char_coord==29){
            char_coord=28;
        }
        table[29][char_coord]=CHAR_SYMBOL;
        table[29][char_coord-1]=SPACE_SYMBOL;

    }
    if (dir=='a'){
        char_coord--;
        if(char_coord==0){
            char_coord=1;
        }
        table[29][char_coord]=CHAR_SYMBOL;
        table[29][char_coord+1]=SPACE_SYMBOL;
    }
}

void shoot(char shot){
    if (shot==' '){
        for (int i = 0; i < 29; i++){
            table[i][char_coord] = SHOOT_SYMBOL;
        }
        print_table();
        for (int i = 0; i < 29; i++){
            table[i][char_coord] = SPACE_SYMBOL;
        }     
        print_table();   
    }
}

void spawn_enemy(){
    int spawn_chance = rand()%1000;

    if (spawn_chance>998){
        int enemy_x = rand()%28;
        int enemy_y = rand()%15;
        table[enemy_y][enemy_x+1]=ENEMY_SYMBOL;
    }
}

int main()
{
    char dir=0;

    printf("An alien species that recharge their fuel from our atmosphere arrived. We must destroy them, or we will end with no atmosphere and die.");
    printf("\nIf the number of aliens get to 15, we loose, and you must avoid it.");
    printf("\n'a' and 'd' to move, 'space' to shoot, press any key to start");getch();

    while (1) {
        if (kbhit()){
            dir = getch();
        }
        move_char(dir);
        shoot(dir);
        dir=0;
        spawn_enemy();
        print_table();

        if (enemy_count==15){
            break;
        }
    }

    system("cls"); 
    printf("We lost, the aliens destroyed all our atmosphere. Press any key to exit.");getch();

    return EXIT_SUCCESS;
}
