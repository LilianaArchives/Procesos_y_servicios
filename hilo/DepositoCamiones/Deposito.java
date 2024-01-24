package DepositoCamiones;

public class Deposito {
    private double litrosDeposito;
    private boolean llenandoDeposito = false;


    //método realiza llenado depósito del camión
    public synchronized double repostarDepositoCamion()
    {
        while (!llenandoDeposito) {
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        llenandoDeposito = false;
        notify();
        return litrosDeposito;
    }
    //método productor llena el depósito
    public synchronized void repostarCisternaCombustible(double litros)
    {
        while (llenandoDeposito){
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        litrosDeposito = litros;
        llenandoDeposito = true;
        notifyAll();
    }

}
