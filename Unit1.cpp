//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner),EditArray(*(TEdit *(*)[9][9])&Edit1),CBArray(*(TCheckBox *(*)[9])&CheckBox1),arrayline((int*)array),EditArrayLine(&Edit1)
{
    ct[0]=clWhite;
    ct[1]=clGray;
    ct[2]=clAqua;
    ct[3]=clYellow;
    ct[4]=clLime;
    ct[5]=clRed;
    ct[6]=clTeal;
    ct[7]=clOlive;
    ct[8]=clPurple;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            array[i][j]=0;
            EditArray[i][j]->Color=ct[0];
        }
    }
    //reflash();

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(EditArray[i][j]->Text=="")
            {
                for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=true;
                }
            }
            else
            {
                for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=false;
                }
                BoolArray[i][j][EditArray[i][j]->Text.ToInt()-1]=true;
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            array[i][j]=0;
            EditArray[i][j]->Tag=0;
            EditArray[i][j]->Color=ct[0];
        }
    }
    reflash();

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(1)//EditArray[i][j]->Text=="")
            {
                for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=true;
                }
            }
            else
            {
                for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=false;
                }
                BoolArray[i][j][EditArray[i][j]->Text.ToInt()-1]=true;
            }
        }
    }
}
void __fastcall TForm1::setGroup(void)
{
    for(int i=18;i<=26;i++)
    {
        for(int j=0;j<9;j++)
        {
            group[i][j]=(i-18)*9+j;
        }
    }
    for(int i=9;i<=17;i++)
    {
        for(int j=0;j<9;j++)
        {
            group[i][j]=(i-9)+j*9;
        }
    }
    if(RadioGroup1->ItemIndex==0)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        group[i*3+j][k*3+l]=k*9+l+j*3+i*27;
                        i=i;
                    }
                }

            }
        }
    }
    else
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0,k=0;j<81;j++)
            {
                if(EditArrayLine[j]->Tag==i)
                {
                    group[i][k]=j;
                    k++;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::reflash(void)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(array[i][j]==0)
            {
                EditArray[i][j]->Text="";
            }
            else
            {
                EditArray[i][j]->Text=IntToStr(array[i][j]);
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(EditArray[i][j]->Text=="")
            {
                /*for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=true;
                }*/
            }
            else
            {
                array[i][j]=EditArray[i][j]->Text.ToInt();
                /*for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=false;
                }
                BoolArray[i][j][EditArray[i][j]->Text.ToInt()-1]=true;*/
            }
        }
    }

    step();
}
bool __fastcall TForm1::step(void)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int s=0,N=-1;
            int s2=0,N2=-1;
            int s3=0,N3=-1;
            int s4=0,N4=-1;
            for(int k=0;k<9;k++)
            {
                if(BoolArray[i][j][k])
                {
                    s++;
                    N=k;
                }
                if(BoolArray[i][k][j])
                {
                    s2++;
                    N2=k;
                }
                if(BoolArray[k][i][j])
                {
                    s3++;
                    N3=k;
                }
                if(BoolArray[j/3*3+k/3][j%3*3+k%3][i])
                {
                    s4++;
                    N4=k;
                }
            }
            if(s==1)
            {
                array[i][j]=N+1;
                EditArray[i][j]->Text=IntToStr(N+1);
            }
            if(s2==1)
            {
                array[i][N2]=j+1;
                EditArray[i][N2]->Text=IntToStr(j+1);
            }
            if(s3==1)
            {
                array[N3][i]=j+1;
                EditArray[N3][i]->Text=IntToStr(j+1);
            }
            if(s4==1)
            {
                array[j/3*3+N4/3][j%3*3+N4%3]=i+1;
                EditArray[j/3*3+N4/3][j%3*3+N4%3]->Text=IntToStr(i+1);
            }
        }
    }

    bool over=true;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(array[i][j]!=0)
            {
                int N=array[i][j]-1;
                for(int k=0;k<9;k++)
                {
                    BoolArray[i][j][k]=false;
                    BoolArray[k][j][N]=false;
                    BoolArray[i][k][N]=false;
                }
                for(int k=i/3*3,l=0;l<3;k++,l++)
                {
                    for(int m=j/3*3,n=0;n<3;m++,n++)
                    {
                        BoolArray[k][m][N]=false;
                    }
                }
                BoolArray[i][j][N]=true;
            }
            else
            {
                over=false;
            }
        }
    }
    return over;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Edit1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button==mbLeft)
    {
    int x;
    AnsiString t=((TEdit*)Sender)->Text;
    if(t=="")
    {
        x=1;
    }
    else
    {
        x=t.ToInt()+1;
    }
    if(x==10) x=1;
    ((TEdit*)Sender)->Text=IntToStr(x);
    }
    if(Button==mbRight)
    {
        AnsiString name=&(((TEdit*)Sender)->Name[5]);
        int index=name.ToInt()-1;
        for(int i=0;i<9;i++)
        {
            CBArray[i]->Checked=BoolArray[index/9][index%9][i];
        }


        ((TEdit*)Sender)->Tag=RadioGroup2->ItemIndex;
        ((TEdit*)Sender)->Color=ct[((TEdit*)Sender)->Tag];
    }
}
//---------------------------------------------------------------------------
bool __fastcall TForm1::check(void)
{
    for(int i=0;i<27;i++)
    {
        for(int j=1;j<9;j++)
        {
            for(int k=0;k<j;k++)
            {
                if(arrayline[group[i][j]]!=0 && arrayline[group[i][k]]!=0 && arrayline[group[i][j]]==arrayline[group[i][k]])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    setGroup();
    for(int i=0;i<81;i++)
    {
        if(EditArrayLine[i]->Text=="")
        {
            arrayline[i]=0;
        }
        else
        {
            arrayline[i]=EditArrayLine[i]->Text.ToInt();
        }
        i=i;
    }
    if(retry(0))
    {
        reflash();
    }
    else
    {
        MessageBox(NULL,"µL¸Ñ","¿ù»~",MB_OK);
    }
}
//---------------------------------------------------------------------------
bool __fastcall TForm1::retry(int index)
{
    if(index>=81)
    {
        return true;
    }
    if(EditArrayLine[index]->Text!="")
    {
        return retry(index+1);
    }
    else
    {
        for(;;)
        {

            arrayline[index]++;
            if(arrayline[index]>9)
            {
                arrayline[index]=0;
                return false;
            }
            if(check())
            {
                if(retry(index+1))
                {
                    return true;
                }
            }
        }
    }
}
