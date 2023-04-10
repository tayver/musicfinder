#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30


typedef struct {
	char songname[50];
	char artistname[15];
	double freql;
	double freqh;
	char base_chord[3];
	int octave;
	int dynamiccount;
	char dynamic[13][10];
} Song;

Song songs[MAX] = { {"Ditto","������",185.0,466.16,"A",3,6,{"p","mP","mf","f","cresc.", "decresc."}},
	{"Congratulations","���̽Ľ�", 207.65, 830.61,"G#m",3,2,{"cresc.","ff"}},
	{"Days Gone By","���̽Ľ�",110.0,739.99,"F#m", 4,3,{"p","cresc.","ff"}},
	{"Sweet Chaos","���̽Ľ�",97.999,783.99,"G",4,2,{"p","ff"}},
	{"Shoot Me","���̽Ľ�", 207.65,830.61, "G#m",3,3,{"p","cresc.","ff"}},
	{"Better Better","���̽Ľ�",146.83,783.99,"D",3,2,{"p","ff"}},
	{"Afraid","���̽Ľ�",138.59, 830.61,"C#m",3,3,{"p","cresc.","ff"}},
	{"Twitter","������",207.65, 466.16,"G#m", 2,6,{"ppp","pp","p","mP","mf","f"}},
	{"I'm Still Fly","������",207.65, 622.25,"G#m", 4,1,{"mf"}},
	{"My First and Last","������",329.63,739.99,"Gm",3,1,{"mf"}},
	{"We Go Up","NCT Dream",369.99,739.99,"A",4,4,{"f","mf","cresc.","decresc."}},
	{"Ridin'","NCT Dream",277.18,554.37,"C#m", 4,4,{"f","mf","cresc.","decresc."}},
	{"Spring Day","BTS",261.63,783.99,"C",4,3,{"p","mP","sf"}},
	{"Dynamite","BTS",293.67,659.26,"D",4,3,{"f","ff","mf"}},
	{"Blood Sweat & Tears","BTS",329.63,659.26,"Em",4,3,{"mf","f","ff"}},
	{"Fake Love","BTS",369.99,739.99,"F#m",4,3,{"mf","f","ff"}},
	{"Butter","BTS",207.65,1244.5,"G#m",4,3,{"p","mf","f"}},
	{"Boy With Luv","BTS",293.67,830.61,"D",2,3,{"p","mf","f"}},
	{"DNA","BTS",466.16,1396.9,"Fm",3,3,{"p","mf","f"}},
	{"Idol","BTS",622.25,1975.5,"D#m",2,3,{"p","mf","f"}},
	{"Dolphin","�����̰�",369.99,830.61,"F#m",2,3,{"f","mf","ff"}},
	{"Nonstop","�����̰�",246.94,622.25,"G#m",3,4,{"p","f","mf","ff"}},
	{"Closer","�����̰�",293.67,739.99,"D",2,4,{"p","f","mf","ff"}},
	{"Windy Day","�����̰�",220.0,554.37,"A",3,4,{"p","f","mf","ff"}},
	{"The Fifth Season (SSFWL)","�����̰�",293.67,739.99,"D",2,4,{"p","f","mf","ff"}},
	{"Secret Garden","�����̰�",207.65,830.61,"G#m",3,4,{"p","f","mf","ff"}},
	{"Remember Me","�����̰�",220.0,440.0,"A",2,4,{"p","f","mf","ff"}},
	{"Liar Liar","�����̰�",185.0,493.88,"F#m",2,4,{"p","f","mf","ff"}},
	{"Coloring Book","�����̰�",196.0,523.25,"G",2,4,{"mP","mf","f","ff"}},
	{"Boombayah","�����ũ",207.65,466.16,"C#m",4,4,{"p","f","ff","cresc."}}};


int findsong(double l, double h, char chd[], int oct, char dym[][10]);
int comfreq(int i, double l, double h);
int comchord(int i, char chd[]);
int comoct(int i, int oct);
int comdy(int i, char dym[][10]);

int k = 0;


int main()
{
	int oct, num;
	double low, high;
	char chord[3];
	char dym[13][10];


	printf("��� ���ļ� ���� �Է����ּ���:(����: 27.5 4186) ");
	scanf(" %lf %lf", &low, &high);
	printf("�⺻ ���� �Է����ּ���: ");
	scanf(" %s", &chord);
	printf("��Ÿ�긦 �Է����ּ���: ");
	scanf(" %d", &oct);
	printf("�Է��� �������� ������ �Է����ּ���: ");
	scanf(" %d", &k);
	for (int i = 0; i < k; i++)
	{
		printf("�������� �Է����ּ���: ");
		scanf(" %s", &dym[i]);
	}

	num = findsong(low, high, chord, oct, dym);

	printf("\n����ϰų� ���� �뷡����� ������ �����ϴ�\n\n\"%s�� %s\"\n",songs[num].artistname, songs[num].songname);

	return 0;
}

int findsong(double l, double h, char chd[], int oct, char dym[][10]) {

	int a;
	int val1;
	int value[50];

	for (int i = 0; i < MAX; i++)
	{
		val1 = 0;
		val1 = val1 + comfreq(i, l, h);
		val1 = val1 + comchord(i, chd);
		val1 = val1 + comoct(i, oct);
		val1 = val1 + comdy(i, dym);

		value[i] = val1;
	}
	a = 0;
	for (int i = 1; i < MAX; i++) {
		if (value[a] < value[i])
			a = i;
		else
			continue;
	}

	return a;
}
int comfreq(int i, double l, double h)
{
	int val = 0;

	if (songs[i].freql <= l) {
		if (songs[i].freqh >= h) {
			val = val + 2;
		}
		else
			val = val + 1;
	}
	else if (songs[i].freqh >= h)
		val = val + 1;
	else
		val = val;

	return val;
}
int comchord(int i, char chd[])
{
	int val = 0;

	if (!strcmp(songs[i].base_chord, chd))
		val = val + 1;
	else
		val = val;

	return val;
}
int comoct(int i, int oct)
{
	int val = 0;

	if (songs[i].octave == oct)
		val = val + 1;
	else
		val = val;
	
	return val;
}
int comdy(int i, char dym[][10])
{
	int val = 0;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int f = 0; f < songs[i].dynamiccount; f++)
			{
				if (!strcmp(songs[i].dynamic[j], dym[j]))
					val = val + 1;
				else
					val = val;
			}
		}
	}

	return val;

}