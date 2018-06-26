#pragma once

#ifndef KNAPSACKITEM_H
#define KNAPSACKITEM_H

#include <string>

class KnapsackItem
{
public:
	KnapsackItem(const std::string& itemName, int value, int weight);
	~KnapsackItem();
	std::string getName() const;
	int getWeight() const;
	int getValue() const;

private:
	std::string m_name;
	int m_value;
	int m_weight;
};

#endif
