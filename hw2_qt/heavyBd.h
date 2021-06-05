class Human
{};

class Employee : protected Human
{};

class Student : public Human
{};

class Starosta : Student
{};

class schoolboy : public Human
{};

class ExcellentPupil : private schoolboy
{};

class Manager : public Employee
{};

class Boss : private Manager
{};

class retiree : public Human
{};

class President : protected Boss
{};

class Dstudent : protected schoolboy
{};

class medalist : ExcellentPupil
{};

class programmer : public Employee
{};