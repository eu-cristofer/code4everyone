# Notes taken during the course

## Vim usage

Highlitght the syntax
```
    :syntax on
```

Adjust the tabs
```
    :set tabstop=4
```

## Tips to run the coda as showed by the instructor

To run the code 08-char_cnt.c with bash input redirect type:
```
    $./a.out < 08-char_cnt.c
```

More information on [gnu.org](https://www.gnu.org/software/bash/manual/html_node/Redirections.html).

## Comma operator
The comma operator is written as this;
```
    expression1, expression2
```
and its semantics are first expression1 gets evaluated. Only after that does expression2 get evaluated and the value of the overall expression is expression2.
```
    c = ( a = 0 , b = 1);
    printf("%d.", c);     //It will print 1
```

## Things to think about

A function largely should should do one thing well. This do one thing, they don't move multiple things.

Keep the function in one page. It should be like a paragraph. It is easy to test. A function is a unit you can manage and test efficiently (pre conditions and pos conditions)

## ADT

Abstract Data Type is a concept or model of a data type. An abstract data type is defined by its behavior (semantics) from the point of view of a user, of the data, specifically in terms of possible values, possible operations on data of this type, and the behavior of these operations. From [Wikipedia](https://en.wikipedia.org/wiki/Abstract_data_type).