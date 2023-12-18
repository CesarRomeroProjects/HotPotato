#ifndef __QUEUE_OF_STRINGS_HPP
#define __QUEUE_OF_STRINGS_HPP

#include <string>
#include <stdexcept>

class QueueEmptyException : public std::runtime_error 
{
public:
	explicit QueueEmptyException(const std::string & err) : std::runtime_error(err) {}
};


class QueueOfStrings
{
private:
	struct QueueNode
	{
		QueueNode(std::string v)
		 : value{v}, nextNode{nullptr}
		 {}
		 std::string value;
		 QueueNode * nextNode;
	};
	QueueNode * frontNode;

public:
	QueueOfStrings();

	// Note:  copy constructors are required.
	// Be sure to do a "deep copy" -- if I 
	// make a copy and modify one, it should not affect the other. 
	QueueOfStrings(const QueueOfStrings & st);
	QueueOfStrings & operator=(const QueueOfStrings & st);
	~QueueOfStrings();

	size_t size() const noexcept;
	bool isEmpty() const noexcept;


	void enqueue(const std::string & elem);


	// both versions of front(), as well as dequeue(), throw a QueueEmptyException if called when empty.
	std::string & front();
	const std::string & front() const;


	// does not return anything.  Just removes. 
	void dequeue();
};



#endif 
