[![Codacy Badge](https://app.codacy.com/project/badge/Grade/851b8fc450d2488f9e685513cfedcff9)](https://app.codacy.com/gh/nragland37/Ai-MiniMax-TicTacToe/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![License](https://img.shields.io/badge/license-MIT-blue)](https://github.com/nragland37/Ai-MiniMax-TicTacToe/blob/main/LICENSE)

# <p align="center"> Unbeatable Tic-Tac-Toe Artificial Intelligence :joystick: </p>

<p align="center">
  <img src="assets/ai-demo.gif" alt="AI Demo">
</p>

## Minimax Algorithm 

1. Considers all potential board layouts that could result from its moves and your responses, like a branching tree of possibilities.
2. Assigns a score to each possible end state (win, loss, or tie). It aims to choose moves leading to the highest-scoring branches (wins for the AI).
3. When it's your turn, the AI assumes you'll make the smartest move against it. It aims to pick moves that force the lowest score on you.

## Alpha-Beta Pruning

**1. Best and Worst Guarantees:**
* **Alpha:** *The best (highest) score the AI can achieve, regardless of your moves, for a given branch of moves.*
* **Beta:** *The worst (lowest) score the AI can force you into, for a given branch of moves.*
  
**2. Smart Pruning:** If the AI ever sees a branch guaranteed to be worse than its current 'Beta' (meaning you found a better move against it), it discards that whole branch without further analysis - saving lots of time! The same logic with 'Alpha' discards poor choices for you.
