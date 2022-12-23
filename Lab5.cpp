//Для похода на Азерот Оргриму Думхаммеру потребовался еще один отряд.
//На призыв явились n орков.Способности в ближнем бою и метании копья
//каждого из них Оргрим сразу же оценил.Теперь же он должен определить кого из
//них назначить солдатом - пехотинцем(grunt), а кого метателем - охотником за
//головами(headhunter).При этом, для того, чтобы отряд был боеспособным,
//необходимо, чтобы было в отряде было не менее g грунтов и не менее h
//хедхантеров.После определения каждого орка в какой - то тип войск, может быть
//определена сила этого отряда, как сумма способностей всех орков в назначенной
//им специализации.
//Напишите программу, определяющую максимально возможную силу вновь
//призванного отряда.
//
//Вход.В первой строке заданы три целых числа n, g, h(1 ≤ n ≤ 10000, 0 ≤ g, h ≤ n).
//Далее идут n строк, в каждой из которых записаны два целых числа в
//диапазоне от 0 до 10000 – способность соответствующего орка в ближнем бою и
//его способность в метании копья.
//
//Выход.Вывести максимальную силу боеспособной армии, которая может
//быть создана из призывников.В случае невозможности создания армии,
//удовлетворяющей заданным условиям, выведите число - 1

#include <iostream>

using namespace std;

struct Warrior
{
	int gr_st, hh_st;
	Warrior() :gr_st(0), hh_st(0) {}
	Warrior(int gr_st, int hh_st) :gr_st(gr_st), hh_st(hh_st){}

	Warrior& operator = (const Warrior& object)
	{
		gr_st = object.gr_st;
		hh_st = object.hh_st;
		return *this;
	}
};

void Sort(Warrior* army, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if ((army[j].gr_st + army[j].hh_st) < (army[j + 1].gr_st + army[j + 1].hh_st))
			{
				Warrior temp = army[j];
				army[j] = army[j + 1];
				army[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n, g, h, st = 0;
	cin >> n >> g >> h;
	Warrior* army = new Warrior[n];
	for (int i = 0; i < n; i++)
	{
		cin >> army[i].gr_st >> army[i].hh_st;
	}
	if (g + h > n)
	{
		st = -1;
		cout << st << endl;
	}
	else
	{
		Sort(army, n);
		for (int i = 0; i < n; i++)
		{
			if (g && h && army[i].gr_st > army[i].hh_st)
			{
				st += army[i].gr_st;
				g--;
			}
			else if (g && h && army[i].gr_st < army[i].hh_st)
			{
				st += army[i].hh_st;
				h--;
			}
			else if (!g && h)
			{
				st += army[i].hh_st;
			}
			else if (g && !h)
			{
				st += army[i].gr_st;
			}
			else
			{
				st += max(army[i].gr_st, army[i].hh_st);
			}
		}
		cout << st << endl;
	}
}
