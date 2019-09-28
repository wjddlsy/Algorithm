# Codeforce 1109 A Sasha and a Bit of Relax

## Solve 

### Bitwise XOR 의 성질

- 만약 $a_l\oplus a_{l+1}\oplus ... \oplus a_{mid}=a_{mid+1} \oplus a_{mid+2}\oplus ...\oplus a_r $ 이라면 xor의 성질에 따라 

   $a_l\oplus a_{l+1}\oplus ... \oplus a_r=0​$

- 따라서, 이 문제는 $r-l+1$ 이 짝수이고 $a_l\oplus a_{l+1}\oplus ... \oplus a_r=0$ 를 만족하는 $(l, r)$ 쌍이 몇 개인지 구하는 문제가 된당 

- $pref_i=a_1 \oplus a_2 \oplus ... \oplus a_i$ 라 하면, $a_l\oplus a_{l+1}\oplus ... \oplus a_r=pref_r\oplus pref_{l-1}$ 

  따라서, $pref_r \oplus pref_{l-1} =0$ 이면 $pref_r=pref_{l-1} $ 이다. 

- 

