#include <stdio.h>

int total_num = 20;

// ターミナルにソートした結果を出力する
void show_data(int num[total_num]){
  for(int i=0; i<total_num; i++){
    printf("%d ", num[i]);
  }
  printf("\n");
}

// 選択ソート
// 最大値最小値を探索し，配列最後の要素と入れ替えていく．
void selection_sort(int num[total_num]){
  printf("選択ソート\n");
  int array_num,min,tmp,count=0;
  for(array_num=0; array_num<total_num; array_num++){
    min = array_num;  // 最小値の配列番号を入れる．
    // for文で回して，minより小さい値があれば置き換える．
    for(int i=array_num+1; i<total_num; i++){
      if(num[i] < num[min]){
        min = i;
      }
    }
    if(min != array_num){
      tmp = num[array_num];
      num[array_num] = num[min];
      num[min] = tmp;
      count++;
    }
  }
  show_data(num);
}

// 素数以外を表示
// 素数以外を表示する
void not_prime_number(int num[total_num]){
  printf("素数以外を表示\n");
  int array_num,flag;
  int count=0;                  // 該当する数を数える
  int not_prime_num[total_num]; // 該当するものをここに格納する
  for(array_num=0; array_num<total_num; array_num++){
    flag = 0;
    for(int i=2; i<num[array_num]; i++){
      if(num[array_num]%i == 0){
        flag = 1;
        break;
      }
    }
    // flagが1の時，not_prime_numに値を追加していく．
    if(flag==1){
      not_prime_num[count] = num[array_num];
      count++;
    }
  }
  total_num = count;
  show_data(not_prime_num);
  selection_sort(not_prime_num);
}

int main(void){

  // 以下データ読み込み用
  // num[20]に値を入れ込んでるだけなので，読まなくて大丈夫．
  FILE *fp;
  int num[total_num];
  fp = fopen("data.txt", "r");
  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 0;
  }
  int count = 0;
  while(fscanf(fp, "%d", &num[count]) != EOF){
    count++;
  }
  fclose(fp);

  not_prime_number(num);

  return 0;
}