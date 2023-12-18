#include "QueueOfStrings.hpp"


// The constructor
QueueOfStrings::QueueOfStrings()
{
	frontNode = nullptr;
}



// Be sure to do a "deep copy" -- if I 
// make a copy and modify one, it should not affect the other. 
// The Copy Constructor
QueueOfStrings::QueueOfStrings(const QueueOfStrings & st)
{
	frontNode = nullptr;

	QueueNode* currentNode{st.frontNode};

	while (currentNode != nullptr) {
		enqueue(currentNode->value);
		currentNode = currentNode->nextNode;
	}
}

// Assignment
QueueOfStrings & QueueOfStrings::operator=(const QueueOfStrings & st)
{
	if (this != &st) {
		while (!isEmpty())
			dequeue();
		
		QueueNode* currentNode{st.frontNode};

		while (currentNode != nullptr) {
			enqueue(currentNode->value);
			currentNode = currentNode->nextNode;
		}
	}
	return *this;
}

// The deconstructor
QueueOfStrings::~QueueOfStrings() 
{
	while (!isEmpty())
		dequeue();
}


size_t QueueOfStrings::size() const noexcept
{
	size_t queueCount{0};
	QueueNode* current{frontNode};

	while (current != nullptr)
	{
		queueCount++;
		current = current->nextNode;
	}

	return queueCount;
}


bool QueueOfStrings::isEmpty() const noexcept
{
	return frontNode == nullptr;
}

void QueueOfStrings::enqueue(const std::string & elem)
{
	QueueNode* newStringNode{new QueueNode(elem)};

	// If the queue is empty, it makes the frontNode point to the new QueueMode
	if (isEmpty())
		frontNode = newStringNode;
	else 
	{
		// Retrieve the frontNode
		QueueNode* currentNode{frontNode};

		// Iterate through the nodes until reaching the final node, which the nextNode points to a nullptr (obiviously)
		while (currentNode->nextNode != nullptr) 
			currentNode = currentNode->nextNode;

		// Create a newNode after the last node previously 
		currentNode->nextNode = newStringNode;
	}
}


std::string & QueueOfStrings::front()
{
	// If there is no string in the front node, then the queue is empty because there should be a string.
	if (isEmpty())
		throw QueueEmptyException{"Queue is Empty"};
	
	// Else, return the string object or value inside the front node or beginning of the linked list.
	return frontNode->value;
}

const std::string & QueueOfStrings::front() const
{
	// If there is no string in the front node, then the queue is empty because there should be a string.
	if (isEmpty())
		throw QueueEmptyException{"Queue is Empty"};
	
	// Else, return the string object or value inside the front node or beginning of the linked list.
	return frontNode->value;
}


// does not return anything.  Just removes. 
void QueueOfStrings::dequeue()
{
	if (isEmpty())
		throw QueueEmptyException("Queue is Empty");
	
	QueueNode* tmp{frontNode}; // Storing the frontNode into a temporary node.
	frontNode = frontNode->nextNode; // Pointing to the next node and storing it inside the frontNode.
	delete tmp; // Removing the frontNode.
}


