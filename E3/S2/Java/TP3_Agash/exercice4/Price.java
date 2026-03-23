public record Price(int gold, int silver){

    public static final int RATE = 13;

    public Price {
        if (silver < 0 || gold < 0) {
            throw new IllegalArgumentException("Invalid price");
        }
    }

    public int toSilver() {
        return gold * RATE + silver;
    }

    public boolean canAfford(Price price) {
        return this.toSilver() >= price.toSilver();
    }

    public Price subtract(Price price) {
        int newGold = gold;
        int newSilver = silver;

        if (newSilver < price.silver) {
            newGold -= 1;
            newSilver += RATE;
        }

        newGold -= price.gold;
        newSilver -= price.silver;

        return new Price(newGold, newSilver);
    }

    @Override 
    public String toString(){
        return gold + "g and " + silver + "s";
    }
}