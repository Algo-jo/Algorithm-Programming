#include <stdio.h>
#include <string.h>

struct data{ 
char location[30];
char city[30];
int price;
int room;
int bathroom;
int carpark;
char type[20];
char furnish[20];
} rumah[4000], selected[4000];
int selectedCount = 0;

void Header(){
    printf("%-26s", "Location");
    printf("%-20s", "City");
    printf("%-10s", "Price");
    printf("%-10s", "Rooms");
    printf("%-10s", "Bathroom");
    printf("%-10s", "Carpark");
    printf("%-12s", "Type");
    printf("%-12s\n", "Furnish");
}

void readFile(int row){
    FILE *file;
    file = fopen("file.csv", "r");
    char title[256]; 
    fgets(title, sizeof(title), file);
    
    for(int i = 0; i < row; i++){
        if(fscanf(file, "%[^;]; %[^;]; %d; %d; %d; %d; %[^;]; %[^\n]\n",
        rumah[i].location, rumah[i].city, &rumah[i].price, &rumah[i].room, 
        &rumah[i].bathroom, &rumah[i].carpark, rumah[i].type, rumah[i].furnish) == 8){
        }
    }
    fclose(file);
}

void display(){ 
    int row = 0;
    printf("Number of rows: ");
    scanf("%d", &row);
    if(row > 3940) row = 3939;
    else if(row <= 0) return;
    readFile(row);
    Header();
    for(int i = 0; i < row; i++){
        printf("%-*s", 26, rumah[i].location);
        printf("%-*s", 20, rumah[i].city);
        printf("%-*d", 10, rumah[i].price);
        printf("%-*d", 10, rumah[i].room);
        printf("%-*d", 10, rumah[i].bathroom);
        printf("%-*d", 10, rumah[i].carpark);
        printf("%-*s", 12, rumah[i].type);
        printf("%-*s\n", 12, rumah[i].furnish);
        selected[selectedCount++] = rumah[i];
    }
    printf("\n");
}

void print(int j){
    printf("%-*s", 26, rumah[j].location);
    printf("%-*s", 20, rumah[j].city);
    printf("%-*d", 10, rumah[j].price);
    printf("%-*d", 10, rumah[j].room);
    printf("%-*d", 10, rumah[j].bathroom);
    printf("%-*d", 10, rumah[j].carpark);
    printf("%-*s", 12, rumah[j].type);
    printf("%-*s\n", 12, rumah[j].furnish);
    selected[selectedCount++] = rumah[j];
}

void Location(char Data[]){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(strcmp(Data, rumah[j].location) == 0){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void City(char Data[]){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(strcmp(Data, rumah[j].city) == 0){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void Price(int Data){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(Data == rumah[j].price){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void Rooms(int Data){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(Data == rumah[j].room){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void Bathroom(int Data){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(Data == rumah[j].bathroom){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void Carpark(int Data){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(Data == rumah[j].carpark){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void Type(char Data[]){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(strcmp(Data, rumah[j].type) == 0){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}
void Furnish(char Data[]){
    int manggil = 1;
    for(int j = 0; j < 3939; j++){
        if(strcmp(Data, rumah[j].furnish) == 0){
            if(manggil == 1){
                Header();
                manggil = -1;
            }
            print(j);
        }
    }
    if(manggil == 1) printf("Data not found\n");
}

void selectRow(){ 
    readFile(3939);
    char column[10] = {0};
    char DataString[20] = {0};
    int DataInteger = 0;
    printf("Choose column: ");
    scanf("%[^\n]", column); getchar();
    if(strcmp(column, "Location") == 0){
        printf("What do you want to find?: ");
        scanf("%[^\n]", DataString);
        printf("Data found! Here's the details:\n");
        Location(DataString);
    }
    else if(strcmp(column, "City") == 0){
        printf("What do you want to find?: ");
        scanf("%[^\n]", DataString);
        printf("Data found! Here's the details:\n");
        City(DataString);
    }
    else if(strcmp(column, "Price") == 0){
        printf("What do you want to find?: ");
        scanf("%d", &DataInteger);
        printf("Data found! Here's the details:\n");
        Price(DataInteger);
    }
    else if(strcmp(column, "Rooms") == 0){
        printf("What do you want to find?: ");
        scanf("%d", &DataInteger);
        printf("Data found! Here's the details:\n");
        Rooms(DataInteger);
    }
    else if(strcmp(column, "Bathroom") == 0){
        printf("What do you want to find?: ");
        scanf("%d", &DataInteger);
        printf("Data found! Here's the details:\n");
        Bathroom(DataInteger);
    }
    else if(strcmp(column, "Carpark") == 0){
        printf("What do you want to find?: ");
        scanf("%d", &DataInteger);
        printf("Data found! Here's the details:\n");
        Carpark(DataInteger);
    }
    else if(strcmp(column, "Type") == 0){
        printf("What do you want to find?: ");
        scanf("%[^\n]", DataString);
        printf("Data found! Here's the details:\n");
        Type(DataString); 
    }
    else if(strcmp(column, "Furnish") == 0){
        printf("What do you want to find?: ");
        scanf("%[^\n]", DataString);
        printf("Data found! Here's the details:\n");
        Furnish(DataString);
    }
    else printf("Data not found\n");
}

void urut(int j){
    char temp0[30] = {0};
    strcpy(temp0, rumah[j].location);
    strcpy(rumah[j].location, rumah[j-1].location);
    strcpy(rumah[j-1].location, temp0);

    char temp1[30] = {0};
    strcpy(temp1, rumah[j].city);
    strcpy(rumah[j].city, rumah[j-1].city);
    strcpy(rumah[j-1].city, temp1);

    int temp2 = rumah[j].price;
    rumah[j].price = rumah[j - 1].price;
    rumah[j - 1].price = temp2;

    int temp3 = rumah[j].room;
    rumah[j].room = rumah[j - 1].room;
    rumah[j - 1].room = temp3;

    int temp4 = rumah[j].bathroom;
    rumah[j].bathroom = rumah[j - 1].bathroom;
    rumah[j - 1].bathroom = temp4;

    int temp5 = rumah[j].carpark;
    rumah[j].carpark = rumah[j - 1].carpark;
    rumah[j - 1].carpark = temp5;

    char temp6[30] = {0};
    strcpy(temp6, rumah[j].type);
    strcpy(rumah[j].type, rumah[j-1].type);
    strcpy(rumah[j-1].type, temp6);

    char temp7[30] = {0};
    strcpy(temp7, rumah[j].furnish);
    strcpy(rumah[j].furnish, rumah[j-1].furnish);
    strcpy(rumah[j-1].furnish, temp7);
}

void sortLokasi(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].location, rumah[j-1].location) < 0){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].location, rumah[j-1].location) > 0){
                    urut(j);
                }
            }
        }
    }
}
void sortCity(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].city, rumah[j-1].city) < 0){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].city, rumah[j-1].city) > 0){
                    urut(j);
                }
            }
        }
    }
}
void sortPrice(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].price < rumah[j-1].price){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].price > rumah[j-1].price){
                    urut(j);
                }
            }
        }
    }
}
void sortRoom(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].room < rumah[j-1].room){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].room > rumah[j-1].room){
                    urut(j);
                }
            }
        }
    }
}
void sortBath(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].bathroom < rumah[j-1].bathroom){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].bathroom > rumah[j-1].bathroom){
                    urut(j);
                }
            }
        }
    }
}
void sortCar(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].carpark < rumah[j-1].carpark){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(rumah[j].carpark > rumah[j-1].carpark){
                    urut(j);
                }
            }
        }
    }
}
void sortType(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].type, rumah[j-1].type) < 0){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].type, rumah[j-1].type) > 0){
                    urut(j);
                }
            }
        }
    }
}
void sortFurnish(char sorting[]){
    if(strcmp(sorting, "asc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].furnish, rumah[j-1].furnish) < 0){
                    urut(j);
                }
            }
        }
    }
    else if(strcmp(sorting, "desc") == 0){
        for(int i = 0; i < 3939; i++){
            for(int j = 3939 - 1; j > i; j--){
                if(strcmp(rumah[j].furnish, rumah[j-1].furnish) > 0){
                    urut(j);
                }
            }
        }
    }
}

void tampilkan(){
    for(int x = 0; x < 10; x++){
            printf("%-*s", 26, rumah[x].location);
            printf("%-*s", 20, rumah[x].city);
            printf("%-*d", 10, rumah[x].price);
            printf("%-*d", 10, rumah[x].room);
            printf("%-*d", 10, rumah[x].bathroom);
            printf("%-*d", 10, rumah[x].carpark);
            printf("%-*s", 12, rumah[x].type);
            printf("%-*s\n", 12, rumah[x].furnish);
            selected[selectedCount++] = rumah[x];
    }
}

void sortBy(){
    readFile(3939);
    char kolom[20] = {0};
    char sorting[5] = {0};
    printf("Choose column: ");
    scanf("%[^\n]", kolom); getchar();

    if(strcmp(kolom, "Location") == 0 || strcmp(kolom, "City") == 0
    || strcmp(kolom, "Price") == 0 || strcmp(kolom, "Rooms") == 0
    || strcmp(kolom, "Bathroom") == 0 || strcmp(kolom, "Carpark") == 0
    || strcmp(kolom, "Type") == 0 || strcmp(kolom, "Furnish") == 0){
        printf("Sort ascending or descending? (asc / desc): ");
        scanf("%s", sorting);
        printf("Data found! Here's the details:\n");
    }
    else{
        printf("Data not found\n");
        return;
    }
    if(strcmp(kolom, "Location") == 0){
        sortLokasi(sorting);
        Header();
        tampilkan();
    }
    else if(strcmp(kolom, "City") == 0){
        sortCity(sorting);
        Header();
        tampilkan();
    }
    else if(strcmp(kolom, "Price") == 0){
        sortPrice(sorting);
        Header();
        tampilkan();
    }
    else if(strcmp(kolom, "Rooms") == 0){
        sortRoom(sorting);
        Header();
        tampilkan();
    }
    else if(strcmp(kolom, "Bathroom") == 0){
        sortBath(sorting);
        Header();
        tampilkan();
    }
    else if(strcmp(kolom, "Carpark") == 0){
        sortCar(sorting);
        Header();
        tampilkan();
    }
    else if(strcmp(kolom, "Type") == 0){
        sortType(sorting);
        Header();
        tampilkan(); 
    }
    else if(strcmp(kolom, "Furnish") == 0){
        sortFurnish(sorting);
        Header();
        tampilkan(); 
    }
}

void writeFile(struct data selected[], int selectedCount){
    char nama[100];
    printf("Please dont use space or any special character in your file name\n");
    printf("File name: ");
    scanf("%s", nama);

    if(strstr(nama, ".csv") == NULL) strcat(nama, ".csv");
    FILE *file = fopen(nama, "w");
    fprintf(file, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");   

    for(int i = 0; i < selectedCount; i++){
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n", selected[i].location,
        selected[i].city, selected[i].price, selected[i].room, selected[i].bathroom,
        selected[i].carpark, selected[i].type, selected[i].furnish);
    }
    printf("Data succesfully written into %s!\n", nama);
    fclose(file);
}

int main(){
    int choice = 0;
    do{
        printf("\nJHouse\n");
        printf("What do you want to do?\n");
        printf("1. Display Data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice); getchar();
        switch(choice){
            case 1:{
                memset(selected, 0, sizeof(selected));
                selectedCount = 0;
                display();
                break;
            }
            case 2:{
                memset(selected, 0, sizeof(selected));
                selectedCount = 0;
                selectRow();
                break;
            }
            case 3:{
                memset(selected, 0, sizeof(selected));
                selectedCount = 0;
                sortBy();
                break;
            }
            case 4:{
                writeFile(selected, selectedCount);
                memset(selected, 0, sizeof(selected));
                selectedCount = 0;
                break;
            }
        }
    }while(choice != 5);
    printf("\nThank you for visiting!\n");
    return 0;
}