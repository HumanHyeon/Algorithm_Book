def solution(price, money, count):
    answer = -1
    end_price = 0
    
    for a in range(count) :
        end_price += price * (a+1)
    
    if(end_price > money) :
        answer = end_price - money
        
    else : 
        answer = 0

    return answer