#include<stdio.h>
#include<string.h>
char movie[20];
struct ticket
{
    char name[20];
    char email_id[45];
    long int p_number;
};
void Detail_reciver(struct ticket t,int a[],int n,FILE *det)
{
    int l,r;
    printf("\nVUI LONG DIEN DAY DU THONG TIN DUOI DAY");
    printf("\nHo va ten:\t");
    scanf("%s",t.name);
    printf("\nSo dien thoai:\t");
    scanf("%ld",&t.p_number);
    printf("\nEmail:\t");
    scanf("%s",t.email_id);
    fputs("So ghe da co: ",det);
    for(int i=0;i<n;i++)
    {
        fprintf(det,"%d",a[i]);
        fputs(", ",det);
    }
    fputs("\n",det);

    fputs(t.name,det);
    fputs("\n",det);

    fputs(t.email_id,det);
    fputs("\n",det);

    fprintf(det,"%ld",t.p_number);
    fputs("\n",det);
    fputs("\n",det);

    fclose(det);
}
void admin()
{
    char admin_id[20],det[25];
    char admin_pass[10],time[10];
    int choice,size;
    FILE *movdet,*d1,*d2;
    char num[5],ch;
    L4:printf("Admin id:\t");
    scanf("%s",admin_id);
    printf("Admin password:\t");
    scanf("%s",admin_pass);
    if(strcmp(admin_id,"admin")==0 && strcmp(admin_pass,"admin")==0)
    {
        L8 :printf("\n1]----->Thay doi ten va thoi gian phim");
        printf("\n2]----->Lay thong tin chi tiet chuong trinh");
        L5:printf("\nNhap lua chon : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            movdet=fopen("Movie_details.txt","w+");
            for(int i=0;i<2;i++)
            {
               num[0]=(i+1)+'0';
               printf("Nhap ten phim:\t");
               scanf("%s",movie);
               printf("Nhap thoi gian chieu:\t");
               scanf("%s",time);
               if(strlen(movie)>0 && strlen(time)>0)
               {
                 fputs(num,movdet);
                 fputs("] ",movdet);
                 fputs(movie,movdet);
                 fputs("\t",movdet);
                 fputs(time,movdet);
                 fputs("\n",movdet);
               }
            }
            printf("Luu thanh cong!!!\n\n");
        }
        else if(choice==2)
        {
            movdet=fopen("Movie_details.txt","a+");
            int i=0;
            while(i<2)
            {
                fgets(det,25,movdet);
                printf("%s",det);
                i++;
            }
            L6:printf("Nhap so phim cho chi tiet nguoi dung : ");
            scanf("%d",&choice);
            if(choice==1)
            {
                d1=fopen("Details1.txt","r+");
                while((ch=fgetc(d1))!= EOF)
                    printf("%c",ch);
                printf("\n\n\n");
                fclose(d1);
            }
            else if(choice==2)
            {
                d2=fopen("Details2.txt","r+");
                while((ch=fgetc(d2))!=EOF)
                printf("%c",ch);
                printf("\n\n\n");
                fclose(d2);
            }
            else
            {
                printf("\nDau vao nhap sai\n");
                goto L6;
            }
        }
        else
        {
            printf("Lua chon sai!!! Thu lai.");
            goto L5;
        }
    }
    else
    {
        printf("\nTai khoan hoac mat khau khong chinh xac!\n");
        goto L4;
    }
    fclose(movdet);
    printf("\n\n----->1] Tiep tuc voi admin\n----->An nut bat ki de thoat\n\n");
    scanf("%d",&choice);
    if(choice==1)
        goto L8;

}

void book(FILE *poi,FILE *seat)
{
    int a=0,tick[80],no=0,occupied;
    struct ticket t1;
    printf("\t\t\t\t\tMAN HINH\n\n");

    int occ[80]={0},i=0;
    while((occupied=getw(seat)) != EOF)
    {
        occ[i]=occupied;
        i++;
    }
    for(int j=0;j<8;j++)
    {
        printf("\t");
        for(int k=0;k<10;k++)
        {
            int flag=0;
            a++;
            for(int r=0;r<80;r++)
            {
                if(occ[r]==a)
                {
                    if(a<10)
                        printf("0%d-H\t",a);
                    else
                        printf("%d-H\t",a);
                    flag=0;
                    break;
                }
                else
                    flag=1;
            }


            if(flag==1)
            {
              if(a<10)
                printf("0%d-S\t",a);
              else
                printf("%d-S\t",a);
            }
        }
        printf("\n");
    }
    printf("\nGia");
    printf("\nGhe [01 - 20]---> 60 000 VND--->Tiet kiem");
    printf("\nGhe [21 - 60]---> 80 000 VND--->Cao cap");
    printf("\nGhe [61 - 80]---> 100 000 VND--->Dac biet");
    L3:printf("\n\nNhap so luong ghe : ");
    scanf("%d",&no);
    if(no>(80-i))
    {
        printf("\nCon nhieu ghe khong co san\n");
        goto L3;
    }
    printf("\nVui long chon ghe cac ghe con lai ");
    for(int i=0;i<no;i++)
    {
        L7:printf("\nTiep tuc:");
        scanf("%d",&tick[i]);
        if(tick[i]>80)
        {
            printf("Oi hong!! Loi dau vao. Thu lai");
            goto L7;
        }
        else
        {
            for(int k=0;k<80;k++)
            {
                if(occ[k]==tick[i])
                {
                    printf("=((!! Ghe da duoc dat truoc. Vui long chon ghe khac");
                    goto L7;
                }
            }
        }
        for(int s=0;s<i;s++)
        {
            if(tick[s]==tick[i])
            {
                printf("\nDa nhap so ghe\n");
                goto L7;
            }
        }
        putw(tick[i],seat);
    }
    fclose(seat);
    a=0;
    Detail_reciver(t1,tick,no,poi);
    float sum=0,tax=0;
    for(int i=0;i<no;i++)
    {
        if(tick[i]>0 && tick[i]<=20)
            sum=sum+50;
        else if(tick[i]>=21 && tick[i]<=60)
            sum=sum+110;
        else
            sum=sum+140;
    }
    printf("\nKhong. so ghe da dat: %d",no);
    printf("\nCho ngoi da dat:");
    for(int r=0;r<no;r++)
    printf("%d, ",tick[r]);
    printf("\nGia ve: Rs.%.2f/-",sum);
    tax=(sum*5)/100;
    printf("\nThue: Rs.%.2f/-",tax);
    printf("\nTong thanh toan: Rs.%.2f/-",sum+tax);
    printf("\nCHUC BAN CO MOT NGAY TOT LANH!!!\n\n\n");

    fclose(poi);

}
int main()
{
    FILE *Md,*d1,*d2,*s1,*s2;
    int choice;
    int ch=0;
    char det[25];
    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("|            CHAO MUNG DEN VOI RAP CHIEU PHIM DQA                  |\n");
    printf("|                          DAT VE NGAY                             |\n");
    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    l1 : printf("1]-----> Dat ve\n");
    printf("2]-----> Admin\n");
    printf("3]----->Thoat\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        Md=fopen("Movie_details.txt","a+");
        int i=0;
        while(i<2)
        {
            fgets(det,25,Md);
            printf("%s",det);
            i++;
        }
        L2:printf("NHAP PHIM BAN CHON\n");
        scanf("%d",&ch);
        if(ch==1)
        {
                d1=fopen("Details1.txt","a+");
                s1=fopen("Seats1.txt","a+");
                book(d1,s1);
                goto l1;
        }
        else if(ch==2)
        {
            d2=fopen("Details2.txt","a+");
            s2=fopen("Seats2.txt","a+");
            book(d2,s2);
            goto l1;
        }
        else
        {
            printf("\nLua chon khong hop le. Thu lai");
            printf("\n");
            goto L2;
        }
    }
    else if(choice==2)
    {
        admin();
        goto l1;
    }
    else if(choice==3)
        printf("\n\n\nCHUC BAN CO MOT NGAY TOT LANH!!!\n");

    else
    {
        printf("Lua chon khong hop le. Vui long nhap lai\n");
        goto l1;
    }
}