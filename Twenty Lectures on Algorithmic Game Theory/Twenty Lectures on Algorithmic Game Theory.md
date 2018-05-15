# Twenty Lectures on Algorithmic Game Theory
*by Tim Roughgarden*

**If you have any advices, please feel free to create an issue.** :smiley:
- - -
## Lecture 1 - Introduction and Examples
### Notes:
* price of anarchy (POA)
* In non-zero-sum game, there is no computationally efficient algorithm for computing Nash equilibrium.

### Exercises:
#### Exercise 1.1
1. In the first round knockout tournament, randomize pairing of the eight winners from round-robin phase.
2. The best team in each round-robin group have rights to select opponent from other group's top 2 teams in the first round knockout. Thus in round-robin phase, each team would try their best to get this rights.

#### Exercise 1.2
Each man will chase the best girl he wants, rather than obeying Nash's soluion.

#### Exercise 1.3
If there exists another mixed strategy different from randomizing uniformly in Rock-Paper-Scissors, that is, one player give an action (e.g. Rock) with probability larger than 1/3. Then the other player has incentive to change her distribution over strategies (e.g. give Paper more often). This is contradicted with the definition of Nash equilibrium.

## Lecture 2 - Mechanism Design Basics
### Notes:
* **Dominant-strategy incentive compatible (DSIC)**: truthful bidding is always a dominant strategy for every bidder and truthful bidders always obtain nonnegative utility.
* Second-price auctions are ideal: (1) strong incentive guarantees (DSIC); (2) strong performance guarantees (welfare maximizing); (3) conputational efficiency (time polynomial).

### Exercises:
#### Exercise 2.1
The second-highest bidder has incentive to bid higher than highest bidder, in this untruthful way, second-highest bidder can obtain positive utility.

#### Exercise 2.2
If:
(1) `b_i > v_i`, the bidder i may have negative utility when her wins the auction and someone bids between `v_i` and `b_i`.
(2) `b_i < v_i`, the bidder i may lose auction when someone bids between `b_i` and `v_i`.

#### Exercise 2.3
Not sure. Top `k`th-highest bidders win the item and `i`th-highest bidder pays a price equal to the `i+1`th-highest bid?

#### Exercise 2.4
Not sure. Just restrict price to not less than c?

#### Exercise 2.5
Lowest bidder wins and pays a price equal to the second-lowest bid.

#### Exercise 2.7
In open ascending auctions, bidding equal to real value is a dominant strategy.

#### Exercise 2.8
Without loss of generality, assume `v_i > v_j, a_i > a_j`. `(v_i * a_i + v_j * a_j) - (v_i * a_j + v_j * a_i) = (v_i - v_j)(a_j - a_i) < 0`. Thus any other assignments' social welfare is lower than assigning the bidder with the `i`th highest valuation to the `i`th best slot.
