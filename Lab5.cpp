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
#include <algorithm>

using namespace std;

struct Warrior
{
	int gr_st, hh_st, diff;
};

bool gr_comp(Warrior first, Warrior second)
{
	if (first.gr_st > second.gr_st)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool diff_comp(Warrior first, Warrior second)
{
	if (first.diff == second.diff)
	{
		return gr_comp(first, second);
	}
	else if (first.diff > second.diff)
	{
		return true;
	}
	else
	{
		return false;
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
		army[i].diff = army[i].gr_st - army[i].hh_st;
	}
	sort(army, army+n, diff_comp);
	/*cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << army[i].gr_st << " " << army[i].hh_st << endl;
	}*/
	if (g + h > n)
	{
		st = -1;
		cout << st << endl;
	}
	else
	{
		for (int i = 0; i < g; i++)
		{
			st += army[i].gr_st;
		}
		for (int i = g; i < g + h; i++)
		{
			st += army[i].hh_st;
		}
		for (int i = g + h; i < n; i++)
		{
			st += max(army[i].gr_st, army[i].hh_st);
		}
		cout << st << endl;
	}
}
