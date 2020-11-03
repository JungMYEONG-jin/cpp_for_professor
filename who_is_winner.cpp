/*  BEST CODE

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
 // Number of blows each fighter can survive:
 int n1 = (fighter1->getHealth() - 1) / fighter2->getDamagePerAttack();
 int n2 = (fighter2->getHealth() - 1) / fighter1->getDamagePerAttack();
 
 return n1 > n2 ? fighter1->getName()
      : n1 < n2 ? fighter2->getName()
      :           firstAttacker;
}




*/

// MY Soltion

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
    if(firstAttacker==fighter1->getName())
      {
      fighter2->setHealth(fighter2->getHealth()-fighter1->getDamagePerAttack());
      if(fighter2->getHealth()<=0)
        return fighter1->getName();
      
      while(fighter1->getHealth()>0 && fighter2->getHealth()>0)
      {
        fighter1->setHealth(fighter1->getHealth()-fighter2->getDamagePerAttack());
        if(fighter1->getHealth()<=0)
          return fighter2->getName();
        
        
        fighter2->setHealth(fighter2->getHealth()-fighter1->getDamagePerAttack());
        if(fighter2->getHealth()<=0)
          return fighter1->getName();
        
        
      }
      
    }else
      {
      fighter1->setHealth(fighter1->getHealth()-fighter2->getDamagePerAttack());
      if(fighter1->getHealth()<=0)
          return fighter2->getName();
      
       while(fighter1->getHealth()>0 && fighter2->getHealth()>0)
      {
         
         
        fighter2->setHealth(fighter2->getHealth()-fighter1->getDamagePerAttack());
        if(fighter2->getHealth()<=0)
          return fighter1->getName();
        fighter1->setHealth(fighter1->getHealth()-fighter2->getDamagePerAttack());
        if(fighter1->getHealth()<=0)
          return fighter2->getName();
        
        
       
        
        
      }
    }
  
  
  
  
}
