class Human
{};

class Student : public Human
{
};

class Starosta : Student
{
};

class schoolboy : public Human
{};

class Employee : protected Human
{};

class Model
{
};

class TreeModel : public Model
{
};

class ListModel : public Model
{
};

class BinaryTreeModel : private TreeModel
{
};