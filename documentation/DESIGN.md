Overview
--------

This document is intended to communicate core architectural decisions within the system. For this reason alone accuracy has suffered. It does not concern itself with interface specifics and primarily focuses on architectural decisions made during the design and development phase, see [API](API.md) for contract details.

All class definitions within the system strictly adhere to the [Opaque Pointer](https://en.wikipedia.org/wiki/Opaque_pointer) idiom. However, this level of detail in the following suite of class diagrams is omitted for clarity; along with pointers, references and other background noise.

Unless otherwise specified all primary data-types originate within the Standard Template Library (STL).

Interpretation
--------------

The key words “MUST”, “MUST NOT”, “REQUIRED”, “SHALL”, “SHALL NOT”, “SHOULD”, “SHOULD NOT”, “RECOMMENDED”, “MAY”, and “OPTIONAL” in this document are to be interpreted as described in [RFC 2119](http://tools.ietf.org/pdf/rfc2119.pdf).

Table of Contents
-----------------

1.	[Overview](#overview)
2.	[Interpretation](#interpretation)
3.	[Terminology](#terminology)
4.	[System Entities](#system-entities)
5.	[Entity Interactions](#entity-interactions)
6.	[Further Reading](#further-reading)

Terminology
-----------

| Term        | Definition                                                                                                                               |
|-------------|------------------------------------------------------------------------------------------------------------------------------------------|
| Bet         | Risk a sum of money or valued item against someone else's on the basis of the outcome of an unpredictable event such as a race or game.  |
| Race        | A competition between runners, horses, vehicles, etc. to see which is the fastest in covering a set course.                              |
| Product     | An game option that is or may be chosen.                                                                                                 |
| Totalisator | a device showing the number and amount of bets staked on a race, to facilitate the division of the total among those backing the winner. |

System Entities
---------------

1.	[Overview](#overview)
2.	[Interpretation](#interpretation)
3.	[Bet](#bet)
4.	[Race](#race)
5.	[Product](#product)
6.	[Settings](#settings)
7.	[Totalisator](#totalisator)

### Bet

Representation of a punters bet detailing stake, winning selection and product.

```
+----------------+
|   <<struct>>   |
|       Bet      |
+----------------+
```

### Race

Representation of a Race.

```
+----------------+
|   <<struct>>   |
|      Race      |
+----------------+
```

### Product

Represents a list of possible betting products.

```
+---------------+
|   <<enum>>    |
|    Product    |
+---------------+
| NONE          |
| WIN           |
| PLACE         |
+---------------+
```

### Settings

Represents the primary point of [Totalisator](#totalisator) configuration.

```
+----------------+
|   <<struct>>   |
|    Settings    |
+----------------+
```

### Totalisator

Primary class containing all the necessary business logic.

```
+---------------------------------------+
|              <<class>>                |
|             Totalisator               |
+---------------------------------------+
| + run(Race,std::vector< Bets >)  void |
| + static create(Settings) Totalisator |
+---------------------------------------+
```

Entity Interactions
-------------------

```
 [main]                         [totalisator]
    |                                 |
    |           create(Settings)      |
    |-------------------------------->|
    |<--------------------------------|
    |                                 |    
    |           run(Race,Bets)        |
    |-------------------------------->|
    |<--------------------------------|
```

Further Reading
---------------

[Opaque Pointer](https://en.wikipedia.org/wiki/Opaque_pointer) - In computer programming, an opaque pointer is a special case of an opaque data type, a datatype declared to be a pointer to a record or data structure of some unspecified type.

[Totalisator](https://en.wikipedia.org/wiki/Tote_board) - A tote board is a large numeric or alphanumeric display used to convey information, typically at a race track (to display the odds or payoffs for each horse) or at a telethon (to display the total amount donated to the charitable organization sponsoring the event).
