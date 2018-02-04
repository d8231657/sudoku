//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit13;
        TEdit *Edit14;
        TEdit *Edit15;
        TEdit *Edit16;
        TEdit *Edit17;
        TEdit *Edit18;
        TEdit *Edit19;
        TEdit *Edit20;
        TEdit *Edit21;
        TEdit *Edit22;
        TEdit *Edit23;
        TEdit *Edit24;
        TEdit *Edit25;
        TEdit *Edit26;
        TEdit *Edit27;
        TEdit *Edit28;
        TEdit *Edit29;
        TEdit *Edit30;
        TEdit *Edit31;
        TEdit *Edit32;
        TEdit *Edit33;
        TEdit *Edit34;
        TEdit *Edit35;
        TEdit *Edit36;
        TEdit *Edit37;
        TEdit *Edit38;
        TEdit *Edit39;
        TEdit *Edit40;
        TEdit *Edit41;
        TEdit *Edit42;
        TEdit *Edit43;
        TEdit *Edit44;
        TEdit *Edit45;
        TEdit *Edit46;
        TEdit *Edit47;
        TEdit *Edit48;
        TEdit *Edit49;
        TEdit *Edit50;
        TEdit *Edit51;
        TEdit *Edit52;
        TEdit *Edit53;
        TEdit *Edit54;
        TEdit *Edit55;
        TEdit *Edit56;
        TEdit *Edit57;
        TEdit *Edit58;
        TEdit *Edit59;
        TEdit *Edit60;
        TEdit *Edit61;
        TEdit *Edit62;
        TEdit *Edit63;
        TEdit *Edit64;
        TEdit *Edit65;
        TEdit *Edit66;
        TEdit *Edit67;
        TEdit *Edit68;
        TEdit *Edit69;
        TEdit *Edit70;
        TEdit *Edit71;
        TEdit *Edit72;
        TEdit *Edit73;
        TEdit *Edit74;
        TEdit *Edit75;
        TEdit *Edit76;
        TEdit *Edit77;
        TEdit *Edit78;
        TEdit *Edit79;
        TEdit *Edit80;
        TEdit *Edit81;
        TButton *Button1;
        TButton *Button2;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TCheckBox *CheckBox8;
    TCheckBox *CheckBox9;
    TPopupMenu *PopupMenu1;
    TLabel *Label1;
    TRadioGroup *RadioGroup1;
    TButton *Button3;
    TRadioGroup *RadioGroup2;
        void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Edit1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
        TEdit *(&EditArray)[9][9];
        TEdit **EditArrayLine;
        TCheckBox *(&CBArray)[9];
        int *arrayline;
        int array[9][9];
        int group[27][9];
        bool BoolArray[9][9][9];
        TColor ct[9];

        void __fastcall reflash(void);
        bool __fastcall step(void);
        bool __fastcall check(void);
        bool __fastcall retry(int index);
        void __fastcall setGroup(void);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
