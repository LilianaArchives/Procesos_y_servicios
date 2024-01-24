package DepositoCamiones;
import java.util.Random;
/**
 * <h1>Clase Productor</h1>
 * <p>Esta clase extiende de la clase Thread. Las instancias de esta clase
 * llenarán su depósito</p>
 * <h2>Atributos</h2>
 * <ul>
 *     <li>random: generador de números aleatorios.</li>
 *     <li>deposito: Depósito de combustible. Llena el depósito del combustible</li>
 * </ul>
 */
public class Productor extends Thread{
    /**
     * Generador de números aleatorios
     */
    private Random random;

    /**
     * Depósito de combustible. Llena el depósito del combustible
     */
    private Deposito deposito;

    /**
     * <h2>Constructor Productor</h2>
     * <p>Parámetro usado para instanciar los atributos de la clase.</p>
     * @param dep  variable de tipo Deposito (depósito de combustible).
     */
    public Productor(Deposito dep)
    {
        random = new Random();
        deposito = dep;

    }

    /**
     * <h2>Método <strong>run</strong></h2>
     * <p>
     * Este método se extiende de la clase Thread que define el comportamiento del hilo.
     * En este caso rellenamos quince veces el depósito de combustible enseñando cada vez cuánta cantidad se ha añadido.
     * </p>
     */
    public void run()
    {
        for (int i = 0; i < 15; i++) {
            double limiteSuperiorLitros = 1000;
            double litrosProducidos = random.nextDouble(limiteSuperiorLitros + Double.MIN_VALUE);
            litrosProducidos = Math.round(litrosProducidos*100)/100.00;
            deposito.repostarCisternaCombustible(litrosProducidos);
            System.out.println("Productor llena el depósito con =>"+ litrosProducidos +" Litros");
            try {
                sleep(1000);
            } catch (InterruptedException e) { }
        }
    }
}
