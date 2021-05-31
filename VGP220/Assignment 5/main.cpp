#include <iostream>
#include <string>
#include "PriorityQueue.h"

//This test will use a priority queue to sort the students by it's grades(priority).
//Students names will be the data.
//Students with greater grade should leave the queue first.

int main(int argc, char* argv[])
{
	PriorityQueue<std::string> priorityQueue({ INT_MIN, "ERROR" });

	priorityQueue.Enqueue({ 50, "John Sinner" });
	priorityQueue.Enqueue({ 75, "Rebecca Bowen" });
	priorityQueue.Enqueue({ 65, "Levigne Stray" });
	priorityQueue.Enqueue({ 82, "Roberta Ruffalo" });
	priorityQueue.Enqueue({ 72, "Jade Carol" });
	priorityQueue.Enqueue({ 98, "Konka Ntobo" });
	priorityQueue.Enqueue({ 100, "Michael Wastren Jr." });
	priorityQueue.Enqueue({ 95, "Leonard Millie" });
	priorityQueue.Enqueue({ 63, "Caroline Wilson" });
	priorityQueue.Enqueue({ 84, "Chloe Marshall" });

	PriorityQueue<std::string>::Data first5[5] =
	{
		priorityQueue.Dequeue(),
		priorityQueue.Dequeue(),
		priorityQueue.Dequeue(),
		priorityQueue.Dequeue(),
		priorityQueue.Dequeue()
	};


	std::cout << "Top 5 students and grades:\n";
	for (int i = 0; i < 5; ++i)
	{
		std::cout << i + 1 << ") " << first5->data << " " << first5->priority << "\n";
	}
	//EXPECTED:
	//Top 5 students and grades:
	//1) Michael Wastren Jr. 100
	//2) Konka Ntobo 98
	//3) Leonard Millie 95
	//4) Chloe Marshall 84
	//5) Roberta Ruffalo 82


	//EXPECTED:
	//Clear the queue with no error.
	for (int i = 0; i < 6; ++i)
	{
		priorityQueue.Dequeue();
	}
}