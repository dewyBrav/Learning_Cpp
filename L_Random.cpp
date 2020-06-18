#include <iostream>
#include "L_Random.h"
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������� time()
#include <random> // ��� std::random_device � std::mt19937  (����� ��������)

unsigned int L_Random::PRNG()
	{
        // ���� ��������� ����� - 4 541
        static unsigned int seed = 4541;

        // ���� ��������� ����� �, � ��� �������, ���������� ����� ��������
        // ��-�� ������������� ����� ������� ����� (� ������������) ������� ��������� ����� ������ �� ����������� - ����� ������
        seed = (8253729 * seed + 2396403);

        // ���� ��������� ����� � ���������� �������� � ��������� �� 0 �� 32 767
        return seed % 32768;
	}
void L_Random::R_Print()
{
    srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����

    for (int count = 0; count < 10; ++count)
    {
        std::cout << rand() << "\t";

        // ���� ������ 5 �����, �� ��������� ������ ����� ������
        if ((count + 1) % 5 == 0)
            std::cout << "\n";
    }
}
void L_Random::Mersen()
{
    std::random_device rd;
    std::mt19937 mersenne(rd()); // �������������� ����� �������� ��������� ��������� ������ 

// ����������: ��-�� ������ ���� � ����������� Code::Blocks (���� �� ����������� Code::Blocks � Windows) - ������� ��� ������� ���� ���� � ���������������� ��������� �������:
// std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // �������������� ����� �������� ��������� ��������� ������

    // ������� ��������� ��������� �����
    for (int count = 0; count < 10; ++count)
    {
        std::cout << mersenne() << "\t";

        // ���� ������ 5 �����, �� ��������� ������ ����� ������
        if ((count + 1) % 5 == 0)
            std::cout << "\n";
    }
}