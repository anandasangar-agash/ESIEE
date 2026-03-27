package fr.uge.rogue;

import java.util.Objects;
import java.util.concurrent.ThreadLocalRandom;

public record Price(int copperTotal){
    public static final int COPPER_PER_SILVER = 25;
    public static final int SILVER_PER_GOLD = 13;
    public static final int COPPER_PER_GOLD = SILVER_PER_GOLD * COPPER_PER_SILVER;

    public Price {
        if (copperTotal < 0){
            throw new IllegalArgumentException("Invalid price.");
        }
    }

  
    public Price(int gold, int silver){
        this(gold * COPPER_PER_GOLD + silver * COPPER_PER_SILVER);
    }

    private int gold(){
        return copperTotal / COPPER_PER_GOLD;
    }

    private int silver(){
        return (copperTotal % COPPER_PER_GOLD) / COPPER_PER_SILVER;
    }

    private int copper(){
        return copperTotal % COPPER_PER_SILVER;
    }

    @Override 
    public String toString(){
        return gold() + "g " + silver() + "s " + copper() + "c";
    }
    
    public static Price randomBelow(Price cost){
        Objects.requireNonNull(cost);
        var rng = ThreadLocalRandom.current();
        return new Price(rng.nextInt(cost.copperTotal));
    }

    public boolean isLowerThan(Price other){
        Objects.requireNonNull(other);
        return copperTotal < other.copperTotal;
    }

    public Price substract(Price other){
        Objects.requireNonNull(other);
        if (isLowerThan(other)){
            throw new IllegalArgumentException("Not enough gold pieces.");
        }
        return new Price(copperTotal - other.copperTotal);
    }
}