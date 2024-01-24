package DepositoCamiones;

public class Refineria {
    public static void main(String[] args) {
        Deposito deposito = new Deposito();
        Productor productorCombustible = new Productor(deposito);
        Camion camion1  = new Camion(deposito, 1);
        Camion camion2  = new Camion(deposito, 2);
        Camion camion3  = new Camion(deposito, 3);
        Camion camion4  = new Camion(deposito, 4);
        Camion camion5  = new Camion(deposito, 5);

        productorCombustible.start();
        camion1.start();
        camion2.start();
        camion3.start();
        camion4.start();
        camion5.start();
    }
}
