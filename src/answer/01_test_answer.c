#include <stdio.h>

int total_num = 20; // 今回データは20個ある

// ターミナルにソートした結果を出力する
void show_data(int sort_num[total_num]){
  for(int i=0; i<total_num; i++){
    printf("%d ", sort_num[i]);
  }
  printf("\n");
}

// バブルソート
// 隣り合う要素の大小を比較しながら整列させていく．
void bubble_sort(int num[total_num]){
  printf("バブルソート\n");
  int array_num,i,tmp;
  for(array_num=0; array_num<total_num; array_num++){
    for(i=total_num-1; i>array_num; i--){
      if(num[i] < num[i-1]){
        // 配列前後の値を入れ替える．tmpで一時的に値を退避させておく．
        // tmp = num[i];
        // num[i] = num[i-1];
        // num[i-1] = tmp;
      }
    }
  }
  show_data(num);
}

// 素数を表示
void prime_number(int num[total_num]){
  printf("素数を表示\n");
  int array_num,flag;          // 配列の番号
  int count=0;                 // 該当する素数の数を数える
  int prime_num[total_num];    // 該当する素数をここに格納していく
  for(array_num=0; array_num<total_num; array_num++){
    flag = 0;
    // for文で2倍3倍..と回して，nの倍数だった場合flagを立てる．
    // for(int i=2; i<num[array_num]; i++){
    //   if(num[array_num]%i == 0){
    //     flag = 1;
    //     break;
    //   }
    // }
    if(flag==0){
      prime_num[count] = num[array_num];
      count++;
    }
  }
  total_num = count;
  show_data(prime_num);
  bubble_sort(prime_num);
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

  prime_number(num);

  return 0;
}