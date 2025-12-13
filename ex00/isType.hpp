#ifndef ISTYPE_HPP
# define ISTYPE_HPP

typedef s_result t_result;

bool isChar(const char *input, t_result *r);
bool isFloat(const char *input, t_result *r, char *end);
bool isNanOrInf(const char *input, t_result *r, char *end);
bool isDoule(const char *input, t_result *r, char *end);
bool isInt(const char *input, t_result *r, char *end);

#endif
