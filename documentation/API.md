Overview
--------

This document is intended to accurately communicate the [Application Programming Interface (API)](https://en.wikipedia.org/wiki/Application_programming_interface) exposed by the Totalisator framework for public consumption.

A description of the frameworks software architecture is provided by the [Design Overview](#DESIGN.md) documentation.

Interpretation
--------------

The key words “MUST”, “MUST NOT”, “REQUIRED”, “SHALL”, “SHALL NOT”, “SHOULD”, “SHOULD NOT”, “RECOMMENDED”, “MAY”, and “OPTIONAL” in this document are to be interpreted as described in [RFC 2119](http://tools.ietf.org/pdf/rfc2119.pdf).

Table of Contents
-----------------

1.	[Overview](#overview)
2.	[Interpretation](#interpretation)
3.	[Bet](#bet)
4.	[Race](#race)
5.	[Product](#product)
6.	[Settings](#settings)
7.	[Totalisator](#totalisator)
8.	[Further Reading](#further-reading)

### Bet

```C++
struct Bet
{
    Product product = { };
    unsigned int stake = 0;
    unsigned int selection = 0;
}
```

Representation of a punters bet detailing stake, winning selection and product.

### Race

```C++
struct Race
{
    unsigned int number_of_runners = 4;
    std::vector< unsigned int > results = { };

    double win_dividend = 0.0;
    std::vector< double > place_dividends = { };
}
```

Representation of a Race.

### Product

```C++
enum Product : uint8_t
{
    NONE = 0,
    WIN = 1,
    PLACE = 2
}
```

[Enumeration](http://en.cppreference.com/w/cpp/language/enum) of possible betting products.

### Settings

```C++
struct Settings
{
    uint8_t win_commission = 15;
    uint8_t place_commission = 12;

    unsigned int place_winner_boundary = 3;
}
```

Represents the primary point of [Totalisator](#totalisator) configuration.

### Totalisator

Primary class containing all the necessary business logic.

#### Methods

-	[run](#totalisatorrun)
-	[create](#totalisatorcreate)

#### Totalisator::run

```C++
void run( Race& race, const std::vector< Bet >& bets );
```

Validates the race and betting arguments before performing the required processing to determine dividends.

##### Parameters

| name | type                       | default value | direction    |
|:----:|----------------------------|:-------------:|:------------:|
| race | [Race](#race)              |      n/a      | input/output |
| race | std::vector< [Bet](#bet) > |      n/a      |    input     |

##### Return Value

The calculated dividends are returned by setting the required Race properties.

##### Exceptions

Throws [std::domain_error](http://en.cppreference.com/w/cpp/error/domain_error) on invalid input.

#### Totalisator::create

```C++
static std::shared_ptr< Totalisator > create( const Settings& settings = { } );
```

Creates a new instance of Totalisator class.

##### Parameters

| name     | type                  | default value | direction |
|:--------:|-----------------------|:-------------:|:---------:|
| settings | [Settings](#settings) |      n/a      |   input   |

##### Return Value

A new default instance or a newly configured instance if the optional argument Settings is supplied.

##### Exceptions

Throws [std::domain_error](http://en.cppreference.com/w/cpp/error/domain_error) on invalid input.

### Further Reading

[C++ Standard](https://isocpp.org/std/the-standard) - The current ISO C++ standard is officially known as ISO International Standard ISO/IEC 14882:2014(E) – Programming Language C++. Want to read the ISO C++ standard, or working drafts of the standard? You have several options, most of them free.

[C++ Reference](http://en.cppreference.com/) - Comprehensive C++ and Standard Template Library (STL) reference.

[Effective STL](https://www.amazon.com/Effective-STL-Specific-Standard-Template/dp/0201749629) - Written for the intermediate or advanced C++ programmer, renowned C++ expert Scott Meyers provides essential techniques for getting more out of the Standard Template Library in Effective STL, a tutorial for doing more with this powerful library.

[Effective C++](https://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876) - “Every C++ professional needs a copy of Effective C++. It is an absolute must-read for anyone thinking of doing serious C++ development. If you’ve never read Effective C++ and you think you know everything about C++, think again.” — Steve Schirripa, Software Engineer, Google
