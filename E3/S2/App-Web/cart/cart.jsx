import * as React from 'react';
import * as ReactDOM from 'react-dom/client';

async function fetchProducts(setProducts){
    const response = await fetch("/api/product", {method: "GET"});
    if(!response.ok){
        throw new Error();
    }
    const data = await response.json();
    setProducts(data);
}

async function fetchPost(articles){
    const object = articles.reduce((acc, v) => {
      acc[v.id] = v.quantity
      return acc;  
    }, {});

    const response = await fetch("/api/buy", {
        method: "POST",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify(object)
    });
    if(!response.ok){
        throw new Error(response.statusText);
    }
}

function ProductRow({product, articles, setArticles}){
    const {id, name, price} = product;

    return <>
    <div className='product-content'>
        <div className='product-info'>
            <h3>{name}</h3>
            <p>${price}</p>
        </div>
        <button className='btn-add-cart' onClick={() => {
            const exist = articles.some( a => id === a.id);
            if(exist){
                const newArticles = articles.map(a => a.id === id ? {...a, quantity : a.quantity + 1} : a);
                setArticles(newArticles);
            } else {
                 setArticles([...articles, {id, name, price, quantity : 1}]);
            }
        }}>Add to Cart</button>
    </div>
    </>
}

function ProductList(){

    const [products, setProducts] = React.useState([]);
    const [articles, setArticles] = React.useState([]);
    React.useEffect(() => {fetchProducts(setProducts);}, []);

    let price = 0;
    articles.map(a => price = price + a.price);

    return <>
        <h3>Products</h3>
        <div>
            {products.map(p => <ProductRow key={p.id} product={p} setArticles={setArticles} articles={articles}/>)}
        </div>
        <Cart articles={articles} setArticles={setArticles} price={price}/>
        <Buy price={price} articles={articles} setArticles={setArticles} />
    </>;
}

function CartArticle({article, articles, setArticles}){

    const {id, name, quantity} = article;

    return <>
    <div className='article-content'>
        <div className='article-info'>
            <b>{name}</b>
            Quantity : {quantity}
            <button className='btn-quantity' onClick={() => {
                const newArticles = articles.map(a => a.id === id ? {...a, quantity : a.quantity + 1} : a);
                setArticles(newArticles);
            }}>+1</button>
        </div>
        <button className='btn-remove-cart' onClick={() => {
            const filteredArticles = articles.filter(a => a.id !== id);
            setArticles(filteredArticles);
        }}>Remove from Cart</button>
    </div>
    </>
}

function Cart({articles, setArticles, price}){

    return <>
    <h3>Cart ${price}</h3>
    <div>
        {articles.map(a => <CartArticle key={a.id} article={a} articles={articles} setArticles={setArticles}/>)}
    </div>
    </>
}

function Buy({price, articles, setArticles}){
   
    return <>
    <h3>Buy</h3>
    <div className='buy-content'>
        <button className='btn-buy' disabled={price === 0 ? true : false} onClick={
            async () => {await fetchPost(articles); setArticles([]);}}>
                Buy for ${price}
        </button>
    </div>
    </>
}

function App() {
    return <div className="app">
        <ProductList />
    </div>;
}

window.onload = () => {
    const appDOM = document.getElementById("App");

    const root = ReactDOM.createRoot(appDOM);
    root.render(<App/>);
};