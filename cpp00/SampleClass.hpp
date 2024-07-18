#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <string>


class Sample
{
  public:

	Sample(void);
	~Sample(void);

	void setFirstName(std::string first);

	std::string firstName;
};

#endif