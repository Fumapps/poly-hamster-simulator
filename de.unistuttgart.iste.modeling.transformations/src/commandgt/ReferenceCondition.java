/**
 */
package commandgt;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Reference Condition</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link commandgt.ReferenceCondition#getSource <em>Source</em>}</li>
 *   <li>{@link commandgt.ReferenceCondition#getTarget <em>Target</em>}</li>
 *   <li>{@link commandgt.ReferenceCondition#getReferenceName <em>Reference Name</em>}</li>
 *   <li>{@link commandgt.ReferenceCondition#isIsCreate <em>Is Create</em>}</li>
 * </ul>
 *
 * @see commandgt.CommandgtPackage#getReferenceCondition()
 * @model abstract="true"
 * @generated
 */
public interface ReferenceCondition extends EObject {
	/**
	 * Returns the value of the '<em><b>Source</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Source</em>' reference.
	 * @see #setSource(InstanceCondition)
	 * @see commandgt.CommandgtPackage#getReferenceCondition_Source()
	 * @model required="true"
	 * @generated
	 */
	InstanceCondition getSource();

	/**
	 * Sets the value of the '{@link commandgt.ReferenceCondition#getSource <em>Source</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Source</em>' reference.
	 * @see #getSource()
	 * @generated
	 */
	void setSource(InstanceCondition value);

	/**
	 * Returns the value of the '<em><b>Target</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Target</em>' reference.
	 * @see #setTarget(InstanceCondition)
	 * @see commandgt.CommandgtPackage#getReferenceCondition_Target()
	 * @model required="true"
	 * @generated
	 */
	InstanceCondition getTarget();

	/**
	 * Sets the value of the '{@link commandgt.ReferenceCondition#getTarget <em>Target</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Target</em>' reference.
	 * @see #getTarget()
	 * @generated
	 */
	void setTarget(InstanceCondition value);

	/**
	 * Returns the value of the '<em><b>Reference Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Reference Name</em>' attribute.
	 * @see #setReferenceName(String)
	 * @see commandgt.CommandgtPackage#getReferenceCondition_ReferenceName()
	 * @model required="true"
	 * @generated
	 */
	String getReferenceName();

	/**
	 * Sets the value of the '{@link commandgt.ReferenceCondition#getReferenceName <em>Reference Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Reference Name</em>' attribute.
	 * @see #getReferenceName()
	 * @generated
	 */
	void setReferenceName(String value);

	/**
	 * Returns the value of the '<em><b>Is Create</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Is Create</em>' attribute.
	 * @see #setIsCreate(boolean)
	 * @see commandgt.CommandgtPackage#getReferenceCondition_IsCreate()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isIsCreate();

	/**
	 * Sets the value of the '{@link commandgt.ReferenceCondition#isIsCreate <em>Is Create</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Is Create</em>' attribute.
	 * @see #isIsCreate()
	 * @generated
	 */
	void setIsCreate(boolean value);

} // ReferenceCondition